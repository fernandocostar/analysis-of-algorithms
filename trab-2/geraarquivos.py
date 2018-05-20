import os
zero = "0"
for i in range(1, 10):
	os.system("env time -v ./ordenacao < testes/Teste"+ zero + str(i)+".txt > saidas/insertionmem"+str(i)+".txt")