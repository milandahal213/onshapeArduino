#include "OnShape.h"


// Your Access Key and Secret Key go here
OnShape myclient("0hOovSkonuPVQkxaT9qDMnIF", "0osaJsHokjFFdQMI2P4TRRSdtGax4HgYsjIbUXH5mSHRa0MO");

char *c;
char cmd[50];
char *value;
char receive[50]; 
int charsread;
int i;
void setup() {

  Serial.begin(9600);
  Serial1.begin(9600);
  while (!Serial);
  while (!Serial1);
  if (Serial1.available()){
    charsread=Serial1.readBytesUntil('\n',receive, sizeof(receive)-1);
    receive[charsread]='\0';
    c=receive;
  }
    myclient.start("virus", "smoothie123");
  }


void loop () {
if (Serial1.available()){
  Serial1.write("sending back love");
    charsread=Serial1.readBytesUntil('\n',receive, sizeof(receive)-1);
    receive[charsread]='\0';
    c=receive;
    i=0;
    while((c[i]!=':')&&i<strlen(c)){
        cmd[i]=c[i];
        i=i+1;
        }
     cmd[i]='\0';
     value=&c[i+1];

     if (!strcmp(cmd,"create")){
      Serial1.write("Create called");
      Serial.println(myclient.newDocument(value));
      }
     if (!strcmp(cmd,"Transform")){
      Serial.println("Transform was called ") ;
      Serial.println(myclient.transformMate(value));
      
     }
     if (!strcmp(cmd,"Assembly")){
      Serial.println("Assembly was called ") ;
      Serial.println(myclient.assemblyData());
      
     }
    }
  }



  /*
  while(Serial1.available()){
    c = Serial1.read();
    if(c!="\n"){
      receive
    receive+=Serial1.read();
  }
    Serial.println(receive);
    receive="";
    if(receive=="send"){
      Serial.write("yay");
      while(!Serial1.available()){
        Serial.write("waiting");
        delay(2000);
        }
      val=Serial1.read();
      Serial.write(val);
      if (val < 10) {
        char sending[]= "abc"; 
        Serial.println(myclient.newDocument(sending));
      }  
    delay(1000);
    val=val+1;
    }
  }
 }*/
