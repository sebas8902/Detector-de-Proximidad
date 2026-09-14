const int trigPin = 10;
const int echoPin = 9;
const int ledPin = 8;

unsigned long duracion;
float distancia;

// Indica si ya se dio la señal
bool objetoDetectado = false;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  Serial.println("===== Sensor Ultrasonico =====");
  Serial.println("Iniciando mediciones...");
  Serial.println();
}

void loop()
{
  // Enviar pulso ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Recibir el eco
  duracion = pulseIn(echoPin, HIGH);

  // Calcular distancia
  distancia = duracion * 0.0343 / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Detectar objeto a menos de 10 cm
  if (distancia < 10 && !objetoDetectado)
  {
    // Encender LED una sola vez
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);

    objetoDetectado = true;

    Serial.println("OBJETO DETECTADO");
  }

  // Cuando el objeto se aleja, permitir una nueva detección
  if (distancia >= 10)
  {
    objetoDetectado = false;
  }

  delay(100);
}
