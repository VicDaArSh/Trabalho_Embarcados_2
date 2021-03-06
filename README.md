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
  
<h1> 1. PROPOSTA </h1> <br/>
  <p> 1.1 O projeto visa o aprendizado de implementação da conexão com uma interface para operação com envio de instruções de comando, recepção e apresentação de estado do equipamento.
  <p> 1.2 Em um nível de comcepção de projeto definiu-se o diagrama de blocos para a organização:
    
  <figure>
      <p align="center"><img src="Imagens/diagrama_blocos1.jpeg"
        height="400"
        <figcaption> <p align="center"> Figura 1.1 - Diagrama de blocos da concepção do projeto </figcaption>
  </figure>


<h1> 2. CONSIDERAÇÕES INICIAIS </h1> <br/>
  <p> 2.1 Para compilar os códigos é necessário a instalação de todas as bibliotecas: <br/>
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
   <p> 2.2 No caso de uso do Linux, o compilador de C/C++ já possui as bibliotecas necessárias para o "Client.c"; <br/>
   <p> 2.3 No caso de uso do Linux, para se compilar o arquivo em C/C++ usar a linha: "gcc -Wall Client.c -pthread -o Client"; <br/>
   <p> 2.4 Para o download da biblioteca referente a Python, usar o comando "pip install pyqt5"; <br/>


<h1> 3. PROJETO </h1>
  <p> 3.1 Inicialmente foi usado os arquivos contidos na pasta "Projeto_Embarcados". Nela usou-se o arquivo "initial.connect.ui" como base. <br/>
  <p> 3.2 Devido a afinidade dos alunos com Python, converteu-se o arquivo inicial em ".py", fazendo uso da "pyuic5 xyz.ui > xyz.py". Para tal é necessário a instalação do pacote "pyqt5-dev-tools". <br>
  <p> 3.3 Para o desenvolvimento do projeto, usou-se os códigos de teste contidos na pasta "Projeto_Embarcados_Python".
  <p> 3.4 A escrita do código do cliente foi feita em linguagem C, para a posterior transferencia para o sistema Embarcado.
  <p> 3.5 Os códigos finais estão contidos na pasta "Projeto_Embarcados_Final".
  <p> 3.6 Primeiramente o projeto foi desenvolvido sem a possibilidade de teste no sistema embarcado. Dessa forma, os códigos foram sintetizados anteriormente, interface gráfica por meio do software de desenvolvimeno Qt e restante em Visual Studio Code, e testados.
  

<h1> 4. SIMULAÇÕES </h1> 
  <p> 4.1 Servidor;

  <figure>
      <p align="center"><img src="Imagens/teste_servidor_interface_inicial.jpeg"
        height="400"
        <figcaption> <p align="center"> Figura 4.1 - Interface do Servidor (menu principal de definição) </figcaption>
  </figure>
    
  Esse menu serve para definir as conexões, como: o IP da máquina que será o host, a porta dentro da qual será usada para o envio de mensagem e aquela para recebimento de mensagens. Dessa forma o codigo pode ser usado em diferentes máquinas.
   
  <figure>
      <p align="center"><img src="Imagens/teste_servidor_interface_posterior.jpeg"
        height="400"
        <figcaption> <p align="center"> Figura 4.2 - Interface do Servidor (monitorando mensagens) </figcaption>
  </figure>
    
  Esse visor apresenta o menu de usuário para envio das mensagens do robô.

  <p> 4.2 Cliente; <br/>
      O cliente foi escrito em linguagem C com o intuito de permitir a inclusão do código já compilado na placa. Os testes primários foram feitos nos computadores pessoais com portas locais. </p>
  
  <figure>
      <p align="center"><img src="Imagens/teste_cliente.jpeg"
        height="400"
        <figcaption> <p align="center"> Figura 4.3 - Prompt do CLIENTE em Windows </figcaption>
  </figure>

  <p> 4.3 Em sistema embarcado (VIOLA);  <br/>
      A tranferência dos códigos se deram fazendo uso dos passos expostos na "aula 04: roteiro_lab_MK". Iniciamente testou-se a conexão com placa, transferindo o código modelo de CLIENTE, a fim de anular erros provenientes do código escrito. </p>

  <figure>
      <p align="center"><img src="Imagens/embarcado_simples.jpeg"
        height="400"
        <figcaption> <p align="center"> Figura 4.4 - Resultado do teste em sistema embarcado de código modelo </figcaption>
  </figure>
  
  Para tal implementação, gravou-se o vídeo "TesteComThreadSimples.mp4", contido na pasta "Vídeos". Agora, tal transferência também se deu com nosso código de CLIENTE.

  <figure>
      <p align="center"><img src="Imagens/embarcado_multithread.jpeg"
        height="400"
        <figcaption> <p align="center"> Figura 4.5 - Resultado do teste em sistema embarcado de nosso código Multithread </figcaption>
  </figure>
  
  Para tal implementação, gravou-se o vídeo "MultiThread.mp4", contido na pasta "Vídeos".

<h1> 5. COMUNICAÇÃO CAN </h1>  
  <p> 5.1 A transmissão CAN está fora do escopo do projeto;  
  
  <p> 5.2 A rede CAN trabalha com diferenças de potenciais, não com valor nominais de tensões;
   <figure>
      <p align="center"><img src="Imagens/CAN_sinal.png"
        height="200"
        <figcaption> <p align="center"> Figura 5.1 - Resultado do teste em sistema embarcado de código modelo </figcaption>
  </figure>
    
  <p> 5.3 A mensagem padrão CAN possui 59 bits, com 11 bits de identificação iniciais, com os seguintes tipos: Data, Remote, Overload e Error Frames; 
   <figure>
      <p align="center"><img src="Imagens/CAN_tabela.jpg"
        height="50"
        <figcaption> <p align="center"> Figura 5.2 - Tabela de bits de CANOpen <br> (Fonte: <a target="_blank" href="https://github.com/VicDaArSh/Trabalho_Embarcados_2/blob/48e2ddc9ad9711ae187e48e4f2c627283f0528d7/WEG-cfw11-manual-da-comunicacao-canopen.pdf"> WEG_CFW </a>)  </figcaption>
  </figure>
    
  <p> 5.4 A estrutura do barramento CAN é definida por dois resistores de acordo com:
  <figure>
      <p align="center"><img src="Imagens/CAN_estrutura.png"
        height="200"
        <figcaption> <p align="center"> Figura 5.3 - Resultado do teste em sistema embarcado de código modelo </figcaption>
  </figure>
