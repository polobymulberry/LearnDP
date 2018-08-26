https
    : // design-patterns.readthedocs.io/zh_CN/latest/creational_patterns/factory_method.html
// https://design-patterns.readthedocs.io/zh_CN/latest/creational_patterns/factory_method.html

#include <iostream>
#include <memory>

      class Log {
public:
  Log() { std::cout << "Log Construct" << std::endl; }
  virtual ~Log() { std::cout << "~Log" << std::endl; }
  virtual void writeLog() = 0;
};

class LogFactory {
public:
  LogFactory() { std::cout << "LogFactory Construct" << std::endl; }
  virtual ~LogFactory() { std::cout << "~LogFactory" << std::endl; }
  virtual std::shared_ptr<Log> createLog() = 0;
};

class FileLog : public Log {
public:
  FileLog() { std::cout << "FileLog Construct" << std::endl; }
  virtual ~FileLog() override { std::cout << "~FileLog" << std::endl; }

  // Log interface
  virtual void writeLog() override {
    std::cout << "Write File Log" << std::endl;
  }
};

class DatabaseLog : public Log {
public:
  DatabaseLog() { std::cout << "DatabaseLog Construct" << std::endl; }
  virtual ~DatabaseLog() override { std::cout << "~DatabaseLog" << std::endl; }

  // Log interface
  virtual void writeLog() override {}
};

class FileLogFactory : public LogFactory {
public:
  FileLogFactory() { std::cout << "FileLogFactory Construct" << std::endl; }
  virtual ~FileLogFactory() override {
    std::cout << "~FileLogFactory" << std::endl;
  }

  // LogFactory interface
  virtual std::shared_ptr<Log> createLog() override {
    return std::make_shared<FileLog>();
  }
};

class DatabaseLogFactory : public LogFactory {
public:
  DatabaseLogFactory() {
    std::cout << "DatabaseLogFactory Construct" << std::endl;
  }
  virtual ~DatabaseLogFactory() override {
    std::cout << "~DatabaseLogFactory" << std::endl;
  }

  // LogFactory interface
  virtual std::shared_ptr<Log> createLog() override {
    return std::make_shared<DatabaseLog>();
  }
};

int main() {
  std::cout << "Factory Method Pattern" << std::endl;

  FileLogFactory fileLogFactory;
  std::shared_ptr<Log> fileLog =
      fileLogFactory.createLog(); // no need to pass class name
  fileLog->writeLog();

  DatabaseLogFactory dbLogFactory;
  std::shared_ptr<Log> dbLog = dbLogFactory.createLog();
  dbLog->writeLog();

  return 0;
}
