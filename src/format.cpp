#include <string>
#include <iostream>

#include "format.h"

using std::string;
using std::to_string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
  string hoursString, minutesString, secondsString;
  int hours = seconds / 3600;
  seconds = seconds % 3600;
  int minutes = seconds / 60;
  int secondsInt = seconds % 60;
  
  hoursString = to_string(hours);
  minutesString = to_string(minutes);
  secondsString = to_string(secondsInt);
  
  if (hours < 10) {
    hoursString = '0' + hoursString;
  }
  if (minutes < 10) {
    minutesString = '0' + minutesString;
  }
  if (secondsInt < 10) {
    secondsString = '0' + secondsString;
  }
  return hoursString + ':' + minutesString + ':' + secondsString;
}