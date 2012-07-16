#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileSystemModel>
#include <QStandardItemModel>
#include <iostream>
#include <QDir>

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new  Ui::MainWindow) {
  ui->setupUi(this);
  setupTreeView ();
}

void MainWindow::setupTreeView(){
  QFileSystemModel *model = new QFileSystemModel;
      model->setRootPath(QDir::currentPath());
  ui->treeView->setModel (model);
  ui->treeView->setAnimated (true);
  ui->treeView->setIndentation (20);
  ui->treeView->setSortingEnabled (true);
}



MainWindow::~MainWindow(){
  delete ui;
}
