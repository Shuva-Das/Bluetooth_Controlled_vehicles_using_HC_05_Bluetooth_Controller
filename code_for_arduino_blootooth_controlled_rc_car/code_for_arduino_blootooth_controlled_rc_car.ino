char t;
 
void setup() {
pinMode(13,OUTPUT);   //left motors forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(10,OUTPUT);   //right motors reverse
pinMode(3,OUTPUT);   //Led
pinMode(4,OUTPUT);   //Led
pinMode(5,OUTPUT);   //Led
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(4,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}
 
else if(t == 'G'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(3,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(3,HIGH);
  digitalWrite(11,HIGH);
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(5,HIGH);
  digitalWrite(13,HIGH);
}

else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}
delay(100);
}
