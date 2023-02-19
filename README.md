# Tugas-Akhir

### Alur menjalankan Prototye
<img src="https://github.com/FaisalT0435/Tugas-Akhir/blob/main/Arsitektur%20perangkat%20keras.jpg" />

1. Menjalankan LiveOV7670.ino di folder Arduino > Algoritma 
2. Sensor pir mendeteksi objek
3. Sensor pir akan mengirim sinyal ke arduino uno untuk mentrigger kamera supaya aktif
4. Kamera akan mengambil gambar dan menyimpan ke Google Drive
5. Menjalankan " Testing data dan MQTT Publisher.ipynb " di folder Testing
6. Pada " Testing data dan MQTT Publisher.ipynb " mengambil data gambar dari google drive dan model Training terbaik yang sudah di save pada algoritma "Training"
7. Link data gambar google drive : " https://drive.google.com/drive/folders/1GQP_gwOTbRVDDdXw_cxD9cg-GrKtB-hV?usp=sharing"
8. Link model training terbaik  : " https://drive.google.com/drive/folders/1YuL6B3foDClI0MK4mL4Qb288fdLqLaYM?usp=sharing"
9. Pada " Testing data dan MQTT Publisher.ipynb " juga menjalankan MQTT publisher untuk mengirim pesan hasil prediksi ke MQTT
10. Pesan yang dikirim ke MQTT hanya hasil prediksinya pest/hama ketika yang terdeteksi tidak pest/hama maka tidak dikirim 
11. Selanjutnya menjalankan "MQTT Subscriber. py" di folder Testing untuk mengambil pesan dari MQTT publisher 
12. Pada "MQTT Subscriber. py" akan megirimkan hasil ke "LiveOV7670.ino" untuk menyalakan buzzer


### Alur Mendapatkan Model Tebaik 
1. Untuk mendapatkan model terbaik menggunakan algoritma Faster RCNN, Mask RCNN, dan Fast RCNN didapatkan dari folder "Training"
2.  Data yang digunakan yaitu data train dan data valid yang sudah di annotasi
3.  File annotasi berupa json
4.  Link data train : " https://drive.google.com/drive/folders/1NUdEVtx8Ij4gSwWLRJ4OylPSKLjBZ9o9?usp=sharing"
5.  Link data valid : " https://drive.google.com/drive/folders/1wWE6XSRtyR3k-AiyT2eUknY25tMo_OFT?usp=sharing" 
6.  Untuk mendapatkan model terbaik membandingkan setelah tunning dan sebelum tunning
7.  Setelah tunning menggunakan optimazer learning rate  0.01
8.  Sebelum tunning tidak menggunakan optimazer 
9.  Model di save pada link : "https://drive.google.com/drive/folders/1YuL6B3foDClI0MK4mL4Qb288fdLqLaYM?usp=sharing"
10.  Selanjutnya model akan dipanggil pada " Testing data dan MQTT Publisher.ipynb "
