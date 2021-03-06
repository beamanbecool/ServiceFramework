//
// Created by Shinan on 2019/2/3.
//

#ifndef SEVICEFRAMEWORK_TCPSERVER_H
#define SEVICEFRAMEWORK_TCPSERVER_H

#include <memory>
#include <vector>
#include <logging.h>
#include "NetAcceptService.h"
#include "NetWorkService.h"
#include "Stream.h"

using namespace std;

class TcpServer
{
public:
  explicit TcpServer(int netWorkServiceNum, unsigned short listenPort, int threadPoolNum = 0);
  ~TcpServer();
  virtual void onLoop();
  void start();
  const shared_ptr<NetAcceptService> &getSpNetAcceptService() const;

protected:
  virtual void onConnection(const SpStream& spStream, const WpNetWorkService& wpNetWorkService) = 0;

private:
  int netWorkServiceNum_;
  int threadPoolNum_;
  unsigned short listenPort_;
  shared_ptr<NetAcceptService> spNetAcceptService_;
  vector<shared_ptr<NetWorkService>> vecSpNetWorkService_;

private:
  bool _startThreadPool();
  bool _startNetAcceptService();
  bool _startNetWorkService();
};

#endif //SEVICEFRAMEWORK_TCPSERVER_H
