void setup_dist() {
  pinMode(trigPin,OUTPUT);
  for (int i = 0; i < sensors; i++){
    pinMode(echo[i],INPUT);
    oldDistance[i]= default_d_value;
    distance[i]  = default_d_value;
  }
  
}

int read_dist(int dir) {
     digitalWrite(trigPin,LOW);
     delayMicroseconds(2);
     
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(10);
     digitalWrite(trigPin, LOW);

     duration = pulseIn(echo[dir], HIGH);
     return duration*0.034/2;
}


int cmp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int get_dist(int dir) {
    int dist[measures];
    for (int i = 0; i < measures; i++) {
      dist[i] = read_dist(dir);
      delay(10);
    }
    
    qsort(dist, measures, sizeof(int), cmp) ;

    int mean = 0;
    for (int i = 1; i < measures-1 ; i++)
      mean += dist[i]; 

    mean /= (measures-2);
    
    return mean;
}


void update_dist() {
  for (int i = 0; i < sensors; i++){
    oldDistance[i] = distance[i];
    distance[i] = get_dist(i);
    delay(10);
  }
}
