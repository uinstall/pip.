1 MPI : message passing interface ;
-
-used to send msg (data/instructions) from one process to another process(computer/workstations)
-helpful when u need several workstations to work together efficiently and effectively  e.g parallel computing-multiple calculations done at same time

COMMANDS:
-
          MPI_SEND: send message 
          MPI_RECEIVE: receive message
          MPI_INIT: initialize mpi computation
          MPI_FINIALIZE : terminate computation
          MPI_COMM_SIZE: determine no of process
          MPI_COMM_RANK: determine process identifier

2 Key-value service fault tolerant:
-
-it is a system that continues to work even if its components fail

we can make key value service fault tolerant :
-
                using spare or reduntant components such as backup OS
                using load balancing to distribute traffic within network
                using fault isolations : to isolate faulty components to prevent spreading 
                using alternative response when primary operation fails

 3 Open source key management tools:
 -
 allows anyone to inspect,modify and enhance source code 

 egnyte: 
 -
Provides a secure environment for sharing sensitive data such as employees records 

Hashicorp:
-
tool for securing storing and accessing sensitive data (eg API KEYS ,encryption keys ,password)

Doppler:
-
able to modify secret values ,set permission ,moniter acces logs 


more egs: Azure key vaults and google cloud secret manager
-

          
