#include <ArduinoJson.h>
#include <Arduino.h>
#include <ConfigManager.h>

ConfigManager configManager;
struct Config {
    char name[20];
    bool enabled;
    int8_t hour;
    char password[20];
} config;

struct Metadata {
    int8_t version;
} meta;
void setup() {
  Serial.begin(9600);
  configManager.setAPName("Demo");
configManager.setAPFilename("/index.html");
configManager.addParameter("name", config.name, 20);
configManager.addParameter("enabled", &config.enabled);
configManager.addParameter("hour", &config.hour);
configManager.addParameter("password", config.password, 20, set);
configManager.addParameter("version", &meta.version, get);
configManager.begin(config);
}  

void loop() {
  configManager.loop();
}
