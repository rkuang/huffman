# Huffman Encoder

This is a C++ program made to encode textfiles using huffman codewords to compress the test down to an optimal size.

The program is broken down into 4 components: a frequency counter, a huffman code generator, an encryptor, and a decryptor.

To compile to program, use the ```make``` command.

To get the frequencies, do
```cat sample.in | ./frequencies```
This will output the ASCII values of each character found and its associated frequency.

To generate the huffman codes, do 
```cat sample.in | ./frequencies | ./huffman```
This will create a ```codewords.txt``` file, which is used as an input to the encryptor and decryptor. It also outputs the optimal bitcount of the compressed file.

To encrypt a textfile, do
```cat sample.in | ./encode codewords.txt > encryption```

To decrypt, do
```cat encryption | ./decode codewords.txt > decryption```