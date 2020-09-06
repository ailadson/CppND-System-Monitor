#include <vector>
#include "processor.h"
#include "linux_parser.h"

using std::vector;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  vector<int> utilization = LinuxParser::CpuUtilization();
  int user = utilization[0];
  int nice = utilization[1];
  int system = utilization[2];
  int idle = utilization[3];
  int iowait = utilization[4];
  int irq = utilization[5];
  int softirq = utilization[6];
  int steal = utilization[7];
  int guest = utilization[8];
  int guest_nice = utilization[9];

  int PrevIdle = previdle + previowait;
  int Idle = idle + iowait;

  int PrevNonIdle = prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal;
  int NonIdle = user + nice + system + irq + softirq + steal;

  int PrevTotal = PrevIdle + PrevNonIdle;
  int Total = Idle + NonIdle;

  float totald = Total - PrevTotal;
  float idled = Idle - PrevIdle;
  
  prevuser = user;
  prevnice = nice;
  prevsystem = system;
  previdle = idle;
  previowait = iowait;
  previrq = irq;
  prevsoftirq = softirq;
  prevsteal = steal;
  prevguest = guest;
  prevguest_nice = guest_nice;

  return (totald - idled) / totald;
}