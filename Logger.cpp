 #include "Logger.h"

void Logger::AddLog(string methodName)
{
	log += "Called Method: " + methodName + "\n";
}

void Logger::Print()
{
	cout << log;
}
