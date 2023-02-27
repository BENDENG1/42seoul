#include <unistd.h>

int ft_strlen(char *str){
	int i = 0;

	while(str[i] != 0 ){
		i++;
	}
	return i;
}


int main(int ac,  char **av){

	int ascii[255];
	int av1_length = ft_strlen(av[1]);
	int av2_length = ft_strlen(av[2]);

	for(int i = 0; i <255;i++){
		ascii[i] = 0;
	}

	if(ac ==3){
		for(int i = 0; i < av1_length;i++){
			for(int j = 0; j < av2_length;j++){
				if(ascii[(int)av[1][i]] != 1 && av[1][i] == av[2][j])
				{
					write(1,&av[1][i],1);
					ascii[(int)av[1][i]] = 1;
				}
			}
		}
	}
	write(1,"\n",1);
}
