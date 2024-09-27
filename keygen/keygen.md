# keygen writeup 

## AS usual , Running the binary to see what what it looks like in EXECUTION : 

![Local Image](./ap/Capture%20d'écran%202024-09-27%20141850.png)
 here the program is asking for an username then asking for Password , the challenge is to figure out how what is the password ! 

 ## decompiling with GHIDRA : 

 ![Local Image](./ap/Capture%20d'écran%202024-09-27%20134807.png)

 as we saw in the execution , the program ask for a username and a paasword then call a function called gen which seems to be something interesting : the function get the username and then return a string thet get compared with the password we provied 

 ## exploting gen function 

 ![Local Image](./ap/Capture%20d'écran%202024-09-27%20134820.png)

 here is the content of the gen function : it is manipulating our input as follow : 

    every byte of the input is XORed with '0x1' then add to it (char)local_24 (get incremented by the index value)
the result of this manipulation is compred with our password , so the program generate a paasword depending on our input which mean if we manage to pass the correct paasword reagarding ou input we can bypass this authentication mechanism :: a simple way to do so is by choosing a username and generating a password with the same mechanism of the gen funtion. 

## solve : 
![Local Image](./ap/Capture%20d'écran%202024-09-27%20140730.png)

## result : 

![Local Image](./ap/Capture%20d'écran%202024-09-27%20114035.png)