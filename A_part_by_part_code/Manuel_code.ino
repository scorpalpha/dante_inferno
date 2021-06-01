/*
    while (Serial.available()) //<-- Manuel code
    {
    char v = Serial.read();
    Serial.println(v);
    switch (v)
    { case 'F':
           if(digitalRead(18)==LOW)
           {
           fwd();
           }
           else
           {Stop();}
           break;
      case 'B':
            back();
            break;
      case 'R':

          right();
          fwd();
          break;

      case 'L':

          left();
          fwd();
          break;

      default:

          Stop();
          break;


    }
    }*/
