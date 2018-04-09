#include "TaskManager.h"

TaskManager manager;

bool LED0toggle() {
  Serial.println("toggle");
  digitalWrite(5, !digitalRead(5));
  return true;
}

void setup() {
  Serial.begin(115200);
  Serial.println("setup");
  pinMode(5, OUTPUT);
  //syntax:
  // int TaskId = manager.addTask(doSth, Interval, Start@boot?) or
  // int TaskId = manager.addTask(doSth,initSth,deinitSth, Interval, Start@boot?)
  // manager.startTask(taskId, startafterbootdelay, stopafterbootdelay, executeForXTimes, bool0=countfromstart/1=countafterexecution)
    int LEDTaskId = manager.addTask(LED0toggle, 1000, false);
    manager.startTask(LEDTaskId, 10000, 20000, 0, 0);
}

void loop() {
  //Serial.print(".");
  manager.runTasks();
}
