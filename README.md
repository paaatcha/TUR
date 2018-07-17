# TORNEIO UNIVERSITÁRIO DE ROBÓTICA 

Neste repositório encontram-se os códigos da [Equipe de Robótica UFES (ERUS)](http://www.erus.ufes.br/) desenvolvidos para o III Torneio Universitário de Robótica, na Universidade Federal de Uberlândia, UFU.

As regras do torneio são descritas no documento [rules](https://github.com/paaatcha/TUR/blob/master/rules.pdf). Em resumo, a competição é uma corrida de robôs na qual existe uma linha durante todo o percurso. O robô deve seguir essa linha e superar alguns desafios, como: subidas, túneis, encruzilhadas, curvas perigosas, etc. Um detalhe importante é que o robô deve fazer isso de **maneira autônoma**.

A estrutura do robô foi desenvolvida utilizando um software de modelagem 3D chamado [openScad](http://www.openscad.org/). Em seguida, essa estrutura foi impressa e utilizada no robô.

O robô possui 10 sensores de luz para identificação do percurso. Para alocar esses sensores foi desenvolvida uma simples PCB que você encontra o modelo [aqui](http://github.com/paaatcha/TUR/eletronica). 


Para controlar o robô foi utilizado um Arduino MEGA, na qual foi implementado um controlador PID no mesmo. Toda essa implementação se encontra na pasta [programação](https://github.com/paaatcha/TUR/tree/master/programacao).

Você pode ver o desempenho do robô na pista oficial no vídeo abaixo:

[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/wrlccVcyYqc/0.jpg)](https://www.youtube.com/watch?v=wrlccVcyYqc)



