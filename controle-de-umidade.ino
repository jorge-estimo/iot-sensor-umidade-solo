/*
 Projeto: Monitoramento de Umidade do Solo
 Descrição: Realiza a leitura de um sensor de umidade do solo e
            acende LEDs de acordo com o nível de umidade detectado.
 Autor: Seu Nome
 Ano: 2025
*/

// Variável que armazena o valor da umidade lida pelo sensor
int moisture = 0;

void setup()
{
  // Pino A0 fornece energia ao sensor de umidade
  pinMode(A0, OUTPUT);

  // Pino A1 recebe o sinal analógico do sensor
  pinMode(A1, INPUT);

  // Inicializa a comunicação serial para monitoramento
  Serial.begin(9600);

  // Configuração dos pinos dos LEDs como saída
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  // Ativa o sensor de umidade fornecendo energia
  digitalWrite(A0, HIGH);
  delay(10); // Aguarda estabilização do sensor

  // Realiza a leitura do valor de umidade
  moisture = analogRead(A1);

  // Desliga o sensor para reduzir corrosão dos eletrodos
  digitalWrite(A0, LOW);

  // Exibe o valor de umidade no monitor serial
  Serial.println(moisture);

  // Desliga todos os LEDs antes de acender o correto
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);

  // Acende LEDs de acordo com o nível de umidade
  if (moisture < 200) {
    digitalWrite(12, HIGH); // Solo muito seco
  } 
  else if (moisture < 400) {
    digitalWrite(11, HIGH); // Umidade baixa
  } 
  else if (moisture < 600) {
    digitalWrite(10, HIGH); // Umidade média
  } 
  else if (moisture < 800) {
    digitalWrite(9, HIGH);  // Umidade alta
  } 
  else {
    digitalWrite(8, HIGH);  // Solo muito úmido
  }

  // Pequeno atraso antes da próxima leitura
  delay(100);
}
