#include<thread>
#include<memory>
#include<vector>
#include<iostream>
#include<mutex>

std::vector<int> getThreadLimits(const int num,const int threads)
{
  int parts_size = num/threads;
  int rem = num%threads;

  std::vector<int> limits;
  limits.push_back(0);

  int curr = 0;

  for(int i=0; i<threads; i++)
  {
    if(i==threads-1)
    {
      curr+=parts_size+rem;
    }
    else
    {
      curr+=parts_size;
    }
    limits.push_back(curr);
  }
  return limits;
}

void threadSum(const std::vector<int>&nums, int left, int right, int& result, std::mutex& locker)
{
  int part_sum = 0;

  for(int i=left; i<right; i++)
  {
    part_sum+=nums[i];
  }

  std::lock_guard<std::mutex> lock(locker);
  result+=part_sum;

  return;
}


int main(int argc, char* argv[])
{
  int num_threads = 5;
  int vec_len = 12;

  if(argc==3)
  {
    num_threads = std::stoi(argv[1]);
    vec_len = std::stoi(argv[2]);
  }

  std::vector<int> nums;

  for(int i=0; i<vec_len; i++)
  {
    nums.push_back(i+1);
  }

  // https://stackoverflow.com/questions/44950439/shared-ptr-to-an-array
  std::shared_ptr<std::thread> t(new std::thread[num_threads-1], std::default_delete<std::thread[]>());

  std::vector<int> limits = getThreadLimits(vec_len, num_threads);

  int result = 0;

  std::mutex locker;

  for(int i=0; i<num_threads-1; i++)
  {
    t.get()[i] = std::thread(threadSum,std::ref(nums),limits[i],limits[i+1], std::ref(result), std::ref(locker));
  }

  threadSum(nums, limits[num_threads-1], limits[num_threads], result, locker);


  for(int i=0; i<num_threads-1; i++)
  {
    t.get()[i].join();
  }

  std::cout<<(result==((vec_len*(vec_len+1))/2))<<std::endl;

  return 0;
}
