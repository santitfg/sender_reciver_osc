/**
 * oscP5sendreceive by andreas schlegel
 * example shows how to send and receive osc messages.
 * oscP5 website at http://www.sojamo.de/oscP5
 */

import oscP5.*;
import netP5.*;

OscP5 oscP5;
NetAddress myRemoteLocation;
float posX;
float posY;

void setup() {
  size(400, 400);
  frameRate(25);
  /* start oscP5, listening for incoming messages at port 12000 */
  oscP5 = new OscP5(this, 54321);
  myRemoteLocation = new NetAddress("127.0.0.1", 12345);
}


void draw() {

  background(0);

  circle(posX*width, posY*height, 50);
}

void mouseDragged() {
  /* in the following different ways of creating osc messages are shown by example */
  OscMessage myMessage = new OscMessage("/position");

  myMessage.add(mouseX/float(width)); /* add an int to the osc message */
  myMessage.add(mouseY/float(height)); /* add an int to the osc message */

  /* send the message */
  oscP5.send(myMessage, myRemoteLocation);
}


/* incoming osc message are forwarded to the oscEvent method. */
void oscEvent(OscMessage m) {
  /* print the address pattern and the typetag of the received OscMessage */
  print("### received an osc message.");
  print(" addrpattern: "+m.addrPattern());
  println(" typetag: "+m.typetag());

  if (m.addrPattern().equals("/position")) {
     posX = m.get(0).floatValue();
     posY = m.get(1).floatValue();
    println(" posX: "+posX);
    println(" posY: "+posY);
  }
}
