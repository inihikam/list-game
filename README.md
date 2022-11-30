# LIST GAME CPP

Ini adalah program menampilkan list game menggunakan struktur doubly linked list.
  Program ini mempunyai 3 fitur yaitu :
    1. Insert Game
    2. Delete Game
    3. Show List Game

Untuk algoritma Insert memiliki beberapa kondisi, antara lain : 
  1. Data huruf pertama baru lebih kecil dari Head
  2. Data huruf pertama baru sama dengan head tetapi setelahnya tidak sama
  3. Data huruf pertama baru lebih besar dari Tail
  4. Data huruf pertama baru sama dengan Tail tetapi setelahnya tidak sama
  5. Data huruf pertama baru lebih besar dari bantu tetapi lebih kecil dari bantu->next (Kondisi ini memastikan bahwa bekerja di tengah)
  6. Data huruf pertama baru sama dengan bantu tetapi setelahnya tidak sama
 
Untuk algoritma Delete memiliki beberapa kondisi, antara lain :
  1. Data hanya ada 1
  2. Data yang akan dihapus berada di depan
  3. Data lebih dari 1 dan di tengah
  4. Data yang akan dihapus berada di belakang 
