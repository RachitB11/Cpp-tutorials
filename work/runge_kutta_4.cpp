// https://scicomp.stackexchange.com/questions/19020/applying-the-runge-kutta-method-to-second-order-odes
#include <valarray>
#include <vector>
#include <iostream>
#include "gnuplot-iostream.h"

const size_t NDIM = 2;

typedef std::valarray<double> Vector;

inline void mysleep(unsigned millis) {
  usleep(millis * 1000);
}

// t is the time and X is the current state
Vector first_order( const double t, const Vector X )
{
  // Right hand side of the ODE to solve, in this case:
  // d/dt(x) = v;
  // d/dt(v) = t;

  // So solving these 2 simple equations the ideal solution should be
  // x = t^3/6 + v0*t + x0
  // v = t^2/2 + v0

  Vector output(NDIM);
  output[0] = X[1];
  output[1] = t;
  return output;
}

// t is the time and X0 is the init state
Vector state_ideal( const double t, const Vector X0 )
{
  // Right hand side of the ODE to solve, in this case:
  // d/dt(x) = v;
  // d/dt(v) = t;

  // So solving these 2 simple equations the ideal solution should be
  // x = t^3/6 + v0*t + x0
  // v = t^2/2 + v0

  Vector output(NDIM);
  output[0] = pow(t,3)/6. + X0[1]*t + X0[0];
  output[1] = pow(t,2)/2. + X0[1];
  return output;
}

int main()
{
  //initialize values

  // State variable X is [position, velocity]
  double init[] = { 0., 0. };
  Vector X( init, NDIM );
  Vector X_euler( init, NDIM );
  Vector X_ideal( init, NDIM );
  Vector X_init( init, NDIM );

  double t = 0.;
  double tMax=5.;
  double dt = 0.1;

  // Initialize the plot.
  Gnuplot gp;

  gp << "set terminal wxt size 1000,500\n";
  gp << "set multiplot layout 2,1 title 'RK4 vs Euler vs Ideal'\n";
  // Vectors to hold the x,t pairs
  std::vector<std::pair<double,double>> x_rk4;
  std::vector<std::pair<double,double>> x_euler;
  std::vector<std::pair<double,double>> x_ideal;
  std::vector<std::pair<double,double>> vel_rk4;
  std::vector<std::pair<double,double>> vel_euler;
  std::vector<std::pair<double,double>> vel_ideal;

  //time loop
  int nSteps = round( ( tMax - t ) / dt );
  for (int stepNumber = 1; stepNumber<=nSteps; ++stepNumber)
  {
    gp.flush();

    // RK4
    Vector k1 = first_order( t, X );
    Vector k2 = first_order( t + dt / 2.0,  X + dt / 2.0 * k1 );
    Vector k3 = first_order( t + dt / 2.0, X + dt / 2.0 * k2 );
    Vector k4 = first_order( t + dt, X + dt * k3 );
    X += dt / 6.0 * ( k1 + 2.0 * k2 + 2.0 * k3 + k4 );

    // Euler
    X_euler += dt * first_order(t,X_euler);

    // Ideal
    X_ideal = state_ideal(t,X_init);

    x_rk4.push_back(std::make_pair(t,X[0]));
    x_euler.push_back(std::make_pair(t,X_euler[0]));
    x_ideal.push_back(std::make_pair(t,X_ideal[0]));
    gp<<"set title 'Position'\nset xrange [0:5.]\nset yrange [0:21.]\n"
      <<"set xlabel't'\nset ylabel 'x'\n";
    gp << "plot '-' with lines title 'rk4', '-' with lines title 'euler', '-' with lines title 'ideal'\n";
    gp.send1d(x_rk4);
    gp.send1d(x_euler);
    gp.send1d(x_ideal);

    vel_rk4.push_back(std::make_pair(t,X[1]));
    vel_euler.push_back(std::make_pair(t,X_euler[1]));
    vel_ideal.push_back(std::make_pair(t,X_ideal[1]));
    gp<<"set title 'Velocity'\nset xrange [0:5.]\nset yrange [0:13.]\n"
      <<"set xlabel 't'\nset ylabel 'x_{dot}'\n";
    gp << "plot '-' with lines title 'rk4', '-' with lines title 'euler', '-' with lines title 'ideal'\n";
    gp.send1d(vel_rk4);
    gp.send1d(vel_euler);
    gp.send1d(vel_ideal);

    mysleep(50);

    t += dt;
  }

  gp<<"unset multiplot\n";

  std::cout<<"Final time: "<<t<<std::endl;
  std::cout<<"Final rk4 position: "<<X[0]<<std::endl;
  std::cout<<"Final rk4 velocity: "<<X[1]<<std::endl;
  std::cout<<"Final euler position: "<<X_euler[0]<<std::endl;
  std::cout<<"Final euler velocity: "<<X_euler[1]<<std::endl;
  std::cout<<"Final ideal position: "<<X_ideal[0]<<std::endl;
  std::cout<<"Final ideal velocity: "<<X_ideal[1]<<std::endl;
}
