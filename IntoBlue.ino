


String response;

void setup() {
    Serial1.begin(115200);
    Serial1.setTimeout(100);
    
    Spark.function("sendCommand", sendCommand);
}

void loop() {
    char recBuffer[255];

    // Read the serial interface until there is no more data or buffer is full.
    // Buffer size will be limited to publish limit
    if (Serial1.available()) 
    {
        Serial1.readBytes(recBuffer, 255);
        Spark.publish("mcintosh-response", recBuffer, 60, PRIVATE); 
    }
    
    delay(100);
}

int sendCommand(String command)
{
    // returns number of bytes written
    return Serial1.write(command);
}

