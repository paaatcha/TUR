# TORNEIO UNIVERSITÁRIO DE ROBÓTICA 

Neste repositório encontram-se os códigos da [Equipe de Robótica UFES (ERUS)](http://www.erus.ufes.br/) desenvolvidos para o III Torneio Universitário de Robótica, na Universidade Federal de Uberlândia, UFU. Participaram deste projeto, além de mim, os alunos de engenharia de computação da UFES, Guilherme Artém e Vanderlei Vieira.

As regras do torneio são descritas no documento [rules](https://github.com/paaatcha/TUR/blob/master/rules.pdf). Em resumo, a competição é uma corrida de robôs na qual existe uma linha durante todo o percurso. O robô deve seguir essa linha e superar alguns desafios, como: subidas, túneis, encruzilhadas, curvas perigosas, etc. Um detalhe importante é que o robô deve fazer isso de **maneira autônoma**.

A estrutura do robô foi desenvolvida utilizando um software de modelagem 3D chamado [openScad](http://www.openscad.org/). Em seguida, essa estrutura foi impressa e utilizada no robô.

![Estrutra](https://github.com/paaatcha/TUR/blob/master/img/modelo-real.png?raw=true)

O robô possui 10 sensores de luz para identificação do percurso. Para alocar esses sensores foi desenvolvida uma simples PCB que você encontra o modelo [aqui](http://github.com/paaatcha/TUR/eletronica). 

![Sensores](https://github.com/paaatcha/TUR/blob/master/img/placa.jpg?raw=true)

Para controlar o robô foi utilizado um Arduino MEGA, na qual foi implementado um controlador PID no mesmo. Toda essa implementação se encontra na pasta [programação](https://github.com/paaatcha/TUR/tree/master/programacao).

Esse robô também foi tema do meu projeto final de graduação que você encontra detalhes [aqui](http://github.com/paaatcha/projeto-graduacao).

Versão 1 do robô (observer que a placa de sensores e o controlador eram diferentes):
![Versao 1](https://github.com/paaatcha/TUR/blob/master/img/1versao.jpg?raw=true)

Versão final (já com arduino mega e os 10 sensores):
![Versao final](https://github.com/paaatcha/TUR/blob/master/img/versao-final.jpg?raw=true)




Você pode ver o desempenho do robô na pista oficial no vídeo abaixo:

[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/wrlccVcyYqc/0.jpg)](https://www.youtube.com/watch?v=wrlccVcyYqc)



