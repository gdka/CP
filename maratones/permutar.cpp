
// PERMUTAR NUM:

void permuta(string ori, string permu){
    if(ori.size()==permu.size()){
            //cout<<permu<<endl;
    }
    for(int i=0; i<ori.size(); i++){
        if(!marcas[i]){
            marcas[i]=true;
            permuta(ori,permu+ori[i]);
            marcas[i]=false;
        }
    }
}
