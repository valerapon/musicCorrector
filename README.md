# musicCorrector

<strong>Oberton</strong> - to delete spectrum point lower then factor  
<strong>Change</strong> - to move spectrum to specified position  
<strong>Equalizer</strong> - to multiply spectrum on linear function  
  
### How to compile:  
```
g++ Obertor.cpp Music/Music.cpp -o Oberton  
g++ Change.cpp Music/Music.cpp -o Change  
g++ Equalizer.cpp Music/Music.cpp -o Equalizer  
```  
### How to run:  
```
./(Name) (input audiofile) (size of block in sec) (factor) (output audiofile)  
```
Example:  
```
./Oberton tmp/1.wav 1 0 output.wav  
```
### Addition:
Folder \"tmp\" contain compiled files, music example: 1.wav  
Folder \"Music\" contain \"Complex\" class, functions ft and fft and other    
