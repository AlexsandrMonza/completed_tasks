void write (int kbd[], int ram[]){
    for(int i=0;i<8;i++){
        ram[i]=kbd[i];
    }
}

void read (int ram[], int gpu[]){
    for(int i=0;i<8;i++){
        gpu[i]=ram[i];
    }
}