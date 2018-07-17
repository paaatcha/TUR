# TORNEIO UNIVERSITÁRIO DE ROBÓTICA 

In this repository, you can find the codes and files of the [UFES robotic team](http://www.erus.ufes.br/) developed to the III University Robotic Tournament (TUR, in Portuguese), at Federal University of Uberlândia, Brazil. This project was developed by a team composed by me, Guilherme Artém and Vanderlei Vieira.

The tournament's rules are described in [rules.pd](https://github.com/paaatcha/TUR/blob/master/rules.pdf). In brief, the competition was a robot race in which the track race had a line that the robot must follow. In addition, there were extra challenges such as slopes, dark parts, crossroads, dangers turns, etc. The robot needed to be **autonomous** and complete the track race as fast as possible.

The robot structure was developed using the 3D software [openScad](http://www.openscad.org/). Next, this structure was printed in a 3D printer and used as the robot "body".

![Estrutra](https://github.com/paaatcha/TUR/blob/master/img/modelo-real.png?raw=true)

The robot had 10 light sensors to track the line. We developed a PCB that you can find [here](http://github.com/paaatcha/TUR/eletronica). 

![Sensores](https://github.com/paaatcha/TUR/blob/master/img/placa.jpg?raw=true)

The robot had an Arduino Mega, in which we implemented a PID control using C++. You can check out code in this [folder](https://github.com/paaatcha/TUR/tree/master/programacao).

Later, this robot became my undergraduate thesis, in which is described more detailed [here](http://github.com/paaatcha/projeto-graduacao).

Robot version 1: (you may note that in this version the robot has an Arduino UNO and the light sensors PCB wasn't the one pictured above)

![Versao 1](https://github.com/paaatcha/TUR/blob/master/img/1versao.jpg?raw=true)

Robot final version: (now it has the Arduino Mega and the developed PCB)
![Versao final](https://github.com/paaatcha/TUR/blob/master/img/versao-final.jpg?raw=true)




Take look at the robot's performance on the official race track:

[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/wrlccVcyYqc/0.jpg)](https://www.youtube.com/watch?v=wrlccVcyYqc)



