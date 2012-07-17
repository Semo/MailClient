#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileSystemModel>
#include <QStandardItemModel>
#include <iostream>
#include <QDir>
#include <QFileDialog>

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new  Ui::MainWindow) {
  ui->setupUi(this);
  setupTreeView ();
}

void MainWindow::setupTreeView(){
  this->model = new QFileSystemModel;
  model->setRootPath(QDir::currentPath());
  ui->treeView->setModel (model);
  ui->treeView->setAnimated (true);
  ui->treeView->setIndentation (20);
  ui->treeView->setSortingEnabled (true);
}

void MainWindow::setWorkingDirectory (){
  QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home",
                                                   QFileDialog::ShowDirsOnly
                                                   | QFileDialog::DontResolveSymlinks);
  //Debug
  std::string strg = dir.toAscii ().data ();
  cout << strg << endl;
  //Debug end

//  model->setRootPath (dir);
//  ui->treeView->setModel (model);
//  ui->treeView->update (model);
}


MainWindow::~MainWindow(){
  delete ui;
}
