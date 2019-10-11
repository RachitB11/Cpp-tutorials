// https://scicomp.stackexchange.com/questions/19020/applying-the-runge-kutta-method-to-second-order-odes
#include <vector>
#include <iostream>
#include "gnuplot-iostream.h"

// Here the state is [x] representing position

// t is the time and X is the current state
// Return : First order differential values of the state
double first_order(const double t, const double X)
{
  // Right hand side of the ODE to solve, in this case:
  // d/dt(x) = 2*t;

  // So solving these simple equations the ideal solution should be
  // x = t^2

  return 2*t;
}

// t is the time and X0 is the init state
// Return ideal value as computed by solving the ODE
double state_ideal( const double t, const double X0 )
{
  // Right hand side of the ODE to solve, in this case:
  // d/dt(x) = 2*t;

  // So solving these simple equations the ideal solution should be
  // x = t^2

  return pow(t,2.0) + X0;
}

int main()
{
  //initialize values

  // State variable X is [position, velocity]
  double init = 0.0;
  double X_rk4 = init;
  double X_euler = init;
  double X_ideal = init;
  double X_init = init;

  double t = 0.;
  double tMax= 5.;
  double dt = 0.5;

  // Vectors to hold the x,t pairs
  std::vector<std::pair<double,double>> x_rk4;
  std::vector<std::pair<double,double>> x_euler;
  std::vector<std::pair<double,double>> x_ideal;

  //time loop
  int nSteps = round( ( tMax - t ) / dt );

  for (int i = 0; i<nSteps; i++)
  {
    // RK4
    double k1 = dt*first_order( t, X_rk4 );
    double k2 = dt*first_order( t + dt / 2.0,  X_rk4 + k1 / 2.0);
    double k3 = dt*first_order( t + dt / 2.0, X_rk4 + k2 / 2.0);
    double k4 = dt*first_order( t + dt, X_rk4 + k3 );
    X_rk4 += ( k1 + 2.0 * k2 + 2.0 * k3 + k4 ) / 6.0;

    // Euler
    X_euler += dt * first_order(t,X_euler);

    // Ideal
    t += dt;
    X_ideal = state_ideal(t+dt,X_init);

    // Store the data in the variables
    x_rk4.push_back(std::make_pair(t,X_rk4));
    x_euler.push_back(std::make_pair(t,X_euler));
    x_ideal.push_back(std::make_pair(t,X_ideal));

    std::cout<<"t: "<<t<<" X_rk4: "<<X_rk4<<" X_euler: "<<X_euler<<" X_ideal: "<<X_ideal<<std::endl;

  }

  // Plotting
  Gnuplot gp;

  gp << "set title 'RK4 vs Euler vs Ideal'\n";
  gp <<"set xlabel't'\nset ylabel 'x'\n";
  gp << "plot '-' with lines title 'rk4', '-' with lines title 'euler', '-' with lines title 'ideal'\n";
  gp.send1d(x_rk4);
  gp.send1d(x_euler);
  gp.send1d(x_ideal);

  // Final values
  std::cout<<"Final time: "<<t<<std::endl;
  std::cout<<"Final rk4 position: "<<X_rk4<<std::endl;
  std::cout<<"Final euler position: "<<X_euler<<std::endl;
  std::cout<<"Final ideal position: "<<X_ideal<<std::endl;
}
