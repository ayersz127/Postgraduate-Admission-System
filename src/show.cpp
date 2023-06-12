#include "..\include\show.h"

#include <iostream>
#include <iomanip>

void showTitle() {
  std::cout << "==============================" << std::endl;
  std::cout << "欢迎使用研究生初试成绩管理系统" << std::endl;
  std::cout << "==============================" << std::endl;
}

void flush() {
  system("cls");
}

void showChoose() {
  std::cout << "请选择你的登录方式：" << std::endl;
  std::cout << "1：以管理员身份登录" << std::endl;
  std::cout << "2：以用户身份登录" << std::endl;
  std::cout << "3：退出系统" << std::endl;
  std::cout << "> ";
}

void showAdmin() {
  std::cout << "请选择你要进行的操作：" << std::endl;
  std::cout << "1：设置分数线" << std::endl;
  std::cout << "2：查看分数线" << std::endl;
  std::cout << "3：导入考生信息" << std::endl;
  std::cout << "4：修改考生信息" << std::endl;
  std::cout << "5：删除考生信息" << std::endl;
  std::cout << "6：添加考生信息" << std::endl;
  std::cout << "7：查询考生信息" << std::endl;
  std::cout << "8：查看合格考生名单" << std::endl;
  std::cout << "9：导出合格考生信息" << std::endl;
  std::cout << "10：处理查分工单" << std::endl;
  std::cout << "11：退出登录" << std::endl;
  std::cout << "> ";
}

void showUser() {
  std::cout << "请选择你要进行的操作：" << std::endl;
  std::cout << "1：查看个人成绩" << std::endl;
  std::cout << "2：提交查分申诉" << std::endl;
  std::cout << "3：查看申诉反馈" << std::endl;
  std::cout << "4：退出登录" << std::endl;
  std::cout << "> ";
}

void showT() {
  // std::cout << "姓名\t准考证号\t报考专业\t是否为应届生\t数学成绩\t外语成绩\t政治成绩\t专业课成绩\t总成绩" << std::endl;
  std::cout << std::left << std::setw(BOARD_SIZE) << "姓名" << 
                std::left << std::setw(BOARD_SIZE) << "准考证号" << 
                std::left << std::setw(BOARD_SIZE * 2) << "报考专业" << 
                std::left << std::setw(BOARD_SIZE) << "是否为应届生" << 
                std::left << std::setw(BOARD_SIZE) << "数学成绩" << 
                std::left << std::setw(BOARD_SIZE) << "外语成绩" << 
                std::left << std::setw(BOARD_SIZE) << "政治成绩" << 
                std::left << std::setw(BOARD_SIZE) << "专业课成绩" << std::endl;
}