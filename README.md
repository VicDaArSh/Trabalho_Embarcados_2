# Trabalho_Embarcados
<p align="center">
Repositório do projeto de Sistemas embarcados - Primeiro semestre de 2021. <br/>
<b> Projeto 5: IHM para braço robótico de reabilitação. </b>

<p align="left">
<br/>
André Gustavo Espinhosa Coladello - 9897797
<br/>
Lucas Ryu Shoji Nakamura - 10308926
<br/>
Victor Daisuke Araki - 10309041
<br/>
<br/>
  

<h1> 1. CONSIDERAÇÕES INICIAIS </h1> <br/>
    1.1 Para compilar os códigos é necessário a instalação de todas as bibliotecas: <br/>
      stdio.h (Client.c) <br/>
      stdlib.h (Client.c) <br/>
      string.h (Client.c) <br/>
      sys/types.h (Client.c) <br/>
      sys/socket.h (Client.c) <br/>
      netinet/in.h (Client.c) <br/>
      unistd.h (Client.c) <br/>
      netdb.h (Client.c) <br/>
      unistd.h (Client.c) <br/>
      pthread.h (Client.c) <br/>
      pyqt5 (mainwindow.py) <br/>
    1.2 No caso de uso do Linux, o compilador de C/C++ já possui as bibliotecas necessárias para o "Client.c"; <br/>
    1.3 No caso de uso do Linux, para se compilar o arquivo em C/C++ usar a linha: "gcc -Wall Client.c -pthread -o Client"; <br/>
    1.4 Para o download da biblioteca referente a Python, usar o comando "pip install pyqt5"; <br/>
  <br/>
  
  
<h1> 2. SIMULAÇÕES </h1>  <br/>

  2.1 Interface;   <br/>
  
  2.2 Cliente;   <br/>
  
  2.3 Servidor;   <br/>
  
  2.4 Total;   <br/>
  
  
<h1> 3. COMUNICAÇÃO CAN </h1>  <br/>
    3.1 A transmissão CAN está fora do escopo do projeto;  <br/>
    3.2 A rede CAN trabalha com diferenças de potenciais, não com valor nominais de tensões;   <br/>
    3.3 A mensagem padrão CAN possui 59 bits, com 11 bits de identificação iniciais, com os seguintes tipos: Data, Remote, Overload e Error Frames;   <br/>
    3.4 Para a transmissão é necessária apenas um fio, dessa forma um barramento com dois fios, ainda são funcionais caso um apresente falha no link;  <br/>

</p>

