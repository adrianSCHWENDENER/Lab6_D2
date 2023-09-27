#include <SPI.h>                                    //Librería de comunicación SPI
#include <SD.h>                                     //Librería para la memoria microSD

int menu;
int resp;
int narchivo;
String imagen;

void setup() {
  resp = 0;
  
  Serial.begin(115200);                             //Iniciar comunicación serial
  SPI.setModule(0);
  
  Serial.print("Initializing SD card...");
  pinMode(12, OUTPUT);                              //Pin 12 slave select

  if (!SD.begin(12)){                               //Si falla
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");           //Se inició la comunicación

}

void loop() {
  Serial.println("Presione el número de la acción que quiere realizar: ");
  Serial.println("1. Ver imagen 1");
  Serial.println("2. Ver imagen 2");
  Serial.println("3. Ver imagen 3");
  Serial.println("4. Crear imagen");
  if(narchivo == 1){
    Serial.println("5. Ver imagen creada");
  }
  menu = 0;
  
  while(menu == 0){
    resp = Serial.read();                           //Leer la respuesta del usuario
    if(resp == '1'){                                //Si la respuesta es 1
      menu = 1;                                     //Ver la imagen 1
    }
    else if(resp == '2'){                           //Si la respuesta es 2
      menu = 2;                                     //Ver la imagen 2
    }
    else if(resp == '3'){                           //Si la respuesta es 3
      menu = 3;                                     //Ver la imagen 3
    }
    else if(resp == '4'){                           //Si la respuesta es 4
      menu = 4;                                     //Crear imagen
    }
    else if(resp == '5' && narchivo == 1){          //Si la respuesta es 5 y existe un nuevo archivo
      menu = 5;                                     //Ver la imagen creada
    }
  }

  while(menu == 1){
    File imagen1 = SD.open("imagen1.txt");          //Abrir archivo imagen1.txt
    if(imagen1){                                    //Si existe
      Serial.println("imagen1.txt:");
      while(imagen1.available()){                   //Mientras haya texto
        Serial.write(imagen1.read());               //Seguir escribiento
      }
      imagen1.close();                              //Cerrar archivo
      Serial.println('\n');                         //Escribir un enter
    }
    else{                                           //Si no existe el archivo
      Serial.println("error opening imagen1.txt");
    }
    menu = 0;                                       //Volver al menú
  }
  while(menu == 2){
    File imagen2 = SD.open("imagen2.txt");          //Abrir archivo imagen2.txt
    if(imagen2){                                    //Si existe
      Serial.println("imagen2.txt:");
      while(imagen2.available()){                   //Mientras haya texto
        Serial.write(imagen2.read());               //Seguir escribiento
      }
      imagen2.close();                              //Cerrar archivo
      Serial.println('\n');                         //Escribir un enter
    }
    else{                                           //Si no existe el archivo
      Serial.println("error opening imagen2.txt");
    }
    menu = 0;                                       //Volver al menú
  }
  while(menu == 3){
    File imagen3 = SD.open("imagen3.txt");          //Abrir archivo imagen3.txt
    if(imagen3){                                    //Si existe
      Serial.println("imagen3.txt:");
      while(imagen3.available()){                   //Mientras haya texto
        Serial.write(imagen3.read());               //Seguir escribiento
      }
      imagen3.close();                              //Cerrar archivo
      Serial.println('\n');                         //Escribir un enter
    }
    else{                                           //Si no existe el archivo
      Serial.println("error opening imagen3.txt");
    }
    menu = 0;                                       //Volver al menú
  }
  while(menu == 4){
    File imagen4 = SD.open("imagen7.txt", FILE_WRITE);//Crear archivo imagen4.txt
    if(imagen4){                                    //Si existe
      Serial.println("Copie aquí su imagen, presione X para salir:");
      char c;
      while(1){
        if (Serial.available()) {
            c = Serial.read();                      //Leer un carácter
            if (c == 'x') {
                break;                              //Salir si el carácter es 'x'
            }
            imagen += c;                            //Agregar el carácter a la cadena
        }
      }
      imagen4.println(imagen);                      //Guardar imagen
      imagen4.close();                              //Cerrar archivo
      Serial.println('\n');                         //Escribir un enter
    }
    else{                                           //Si no existe el archivo
      Serial.println("error opening imagen4.txt");
    }
    narchivo = 1;                                   //Hay un archivo nuevo
    menu = 0;                                       //Volver al menú
  }
  while(menu == 5){
    File imagen4 = SD.open("imagen7.txt");          //Abrir archivo imagen4.txt
    if(imagen4){                                    //Si existe
      Serial.println("imagen4.txt:");
      while(imagen4.available()){                   //Mientras haya texto
        Serial.write(imagen4.read());               //Seguir escribiendo
      }
      imagen4.close();                              //Cerrar archivo
      Serial.println('\n');                         //Escribir un enter
    }
    else{                                           //Si no existe el archivo
      Serial.println("error opening imagen4.txt");
    }
    menu = 0;                                       //Volver al menú
  }
}
