#include "logger.h"

shw3::Logger::Logger() {
	this->filestream.open("..\\" TARGET_NAME ".log");
}

shw3::Logger::~Logger() {
	if (this->filestream.is_open()) {
		std::lock_guard<std::mutex> guard(mtx);
		filestream.flush();
		filestream.close();
	}
}

void shw3::Logger::writeLine() {
	if (this->filestream.is_open()) {
		std::lock_guard<std::mutex> guard(mtx);
		filestream << std::endl;
	}
}

std::string shw3::Logger::getTimestamp() {
	char buffer[256];
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	strftime(buffer, 256, "[%Y-%m-%d %H:%M:%S]", &timeinfo);
	return std::string(buffer);
}

std::string shw3::Logger::getThreadId()
{
	std::stringstream stream;
	stream
		<< "0x"
		<< std::uppercase
		<< std::setfill('0')
		<< std::setw(4)
		<< std::hex
		<< std::this_thread::get_id()
		<< std::dec
		<< std::setw(0)
		<< std::setfill(' ');
	return stream.str();
}

std::string shw3::Logger::getLogLevelString(LogLevel level)
{
	switch (level) {
	case LL_NON:
		return "NON";
		break;
	case LL_ERR:
		return "ERR";
		break;
	case LL_WRN:
		return "WRN";
		break;
	case LL_NFO:
		return "NFO";
		break;
	case LL_DBG:
		return "DBG";
		break;
	case LL_TRC:
		return "TRC";
		break;
	default:
		return "UNK";
	}
}