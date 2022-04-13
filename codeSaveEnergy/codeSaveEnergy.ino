#include <SoftwareSerial.h>//adicionando a biblioteca para comunicar com a porta serial
//declarando as variáveis e associando as portas que irão utilizar.
int botao = 3;
int sensor = 6;
int contatora = 7;
bool estadobotao = 0;
 
void setup()
{
  //Definindo estado inicial do botão, quando sitema for ligado, ou resetado.
  
  pinMode(botao, INPUT_PULLUP); 
  pinMode(sensor, INPUT_PULLUP); 
  pinMode(contatora, OUTPUT);
  digitalWrite(contatora,HIGH);
  Serial.begin(9600);
  Serial.println("SISTEMA ENERGY SAVER HE SOLUCOES");
  Serial.println("SISTEMA PRONTO");
  Serial.println("WHATSAPP 48 991302114");
  estadobotao = 0;

   //Configura o botão de interrupção, que reseta o programa.
  
  attachInterrupt(digitalPinToInterrupt(botao), estadobotao5, FALLING);
   }
 
void loop()
{   
    estadobotao = 0; //Define a variavel estado botão, onde no cenário real, será realizado com botoeira, ou botão comum de campainha.
    Serial.println("PORTA FECHADA");
    if(digitalRead(sensor) == HIGH) // Lendo estado do sensor magnético instalado na porta de acesso do local.
  {         
      Serial.println("PORTA ABERTA"); //Se sensor detectou porta aberta, envia a informação para a serial.
      delay(5000); //Aguardando tempo de delay para tomar ação, aqui em mili segundos.
       if(estadobotao == 0) // Se após a passagem do tempo configurado o botão não for pressionado, o rele que aciona a contatora será desligado.
         {
              digitalWrite(contatora,LOW);
              Serial.println("TIMER EXCEDIDO - CONTATORA DESLIGADA"); 
          }
           if((digitalRead(sensor) == LOW) && (estadobotao == 1)) //Se botão for acionado, será liberado novamente a contato pelo tempo do delay se a porta estiver aberta, se for presisonado com a porta fechado, sistema todo ligado e estabelecido, aguaradndo nova leitura do sensor da porta. 
            {
              digitalWrite(contatora,HIGH);
              Serial.println("TIMER EXCEDIDO - PORTA FECHADA - BOTAO ACIONADO - CONTATORA LIGADA"); 
              }
         }
}

// Função para controlar o estado do botão, e se o mesmo foi pressionado. 
 
void estadobotao5() {
      digitalWrite(contatora,HIGH);
      Serial.println("BOTAO ACIONADO - CONTATORA LIGADA"); 
      estadobotao = 1;
}
 
