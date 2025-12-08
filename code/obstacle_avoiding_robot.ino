// Motor Pins
// Forward  -> 3 and 6
// Backward -> 5 and 11

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

void setup()
{
    Serial.begin(9600);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(11, OUTPUT);
}

void loop()
{
    long duration;
    long distanceCm;

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH);

    distanceCm = duration / 29.1 / 2;

    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");

    if (distanceCm < 30)
    {
        // Obstacle detected

        digitalWrite(3, HIGH);
        digitalWrite(6, LOW);

        digitalWrite(5, LOW);
        digitalWrite(11, LOW);

        delay(500);

        digitalWrite(3, LOW);
        digitalWrite(6, LOW);

        digitalWrite(5, LOW);
        digitalWrite(11, LOW);
    }
    else
    {
        // Move Forward

        digitalWrite(3, HIGH);
        digitalWrite(6, HIGH);

        digitalWrite(5, LOW);
        digitalWrite(11, LOW);
    }

    delay(10);
}