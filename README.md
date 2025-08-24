# rc-bluetooth-steering
Program mobil aki RC dengan bluetooth, motor driver yang dipakai adalah BTS7960 agar kuat untuk memasok motor 12V dengan Amper besar (max 42A) agar dapat dikendari oleh orang dewasa (beban max 70kg permukaan lantai/datar). <br>
Pada program ini steering menggunakan servo rakitan menggunakan motor high torsi yang diberi potensio 10k, namun jika ingin lebih simpel dapat menggunakan servo min 40 kg.cm


# Komponen 
<ol>
  <li>Arduino uno (1)</li>
  <li>Potensio 10k (1)</li>
  <li>HC-05 (1)</li>
  <li>L298N (1)</li>
  <li>BTS7960 (2)</li>
</ol>

# Pin 
<ul>
  <li>BTS7960 A <br> <img width="486" height="396" alt="PIN BTS7960 A" src="https://github.com/user-attachments/assets/19bbc715-6fe2-44ba-8638-117edeca3aa8" /></li>
  <li>BTS7960 B <br> <img width="486" height="396" alt="PIN BTS7960 B" src="https://github.com/user-attachments/assets/435b2179-3553-40fa-83f3-76595e89e16b" /></li>
  <li>HC-05 <br> <img width="486" height="396" alt="PIN HC-05" src="https://github.com/user-attachments/assets/abdad4a6-02d6-444c-a561-5c4e198f13b8" /></li>
  <li>Potensio 10k <br> pin analog 0 di arduino</li>
</ul>

# Diagram
![Diagram RC](https://github.com/user-attachments/assets/9c1333ae-364d-44d6-8e06-1064e32826ea)

# Remote/controller
untuk pengendali bisa menggunakan aplikasi RC bluetooth yang ada di playstore atau apk buatan braulio (BluetoothRCcontroll) 

