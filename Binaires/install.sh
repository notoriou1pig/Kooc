#!/bin/sh

cd pyrser;
sudo python3.3 setup.py build;
sudo python3.3 setup.py install;
cd ..;

cd cnorm;
sudo python3.3 setup.py build;
sudo python3.3 setup.py install;
