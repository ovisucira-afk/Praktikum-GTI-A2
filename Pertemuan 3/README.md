<img width="904" height="632" alt="Screenshot 2026-03-24 084931" src="https://github.com/user-attachments/assets/02dd6239-5076-4d29-8a5b-4f057f4d06f6" /># PERTEMUAN 3
## Nama : Ovilia Suci Ramadhani
## NIM : 24060124120040
## Lab : A2

**Asisten Praktikum :**
- Siriel Wafa Nuriel Fahri
- Indah Nurul Janah

1. Proyeksi
   <img width="1365" height="767" alt="Screenshot 2026-03-24 054333" src="https://github.com/user-attachments/assets/4b33ec03-2f97-4d19-9150-23a83a3d606d" />

2. Kubus Berotasi
   <img width="1365" height="767" alt="Screenshot 2026-03-24 054529" src="https://github.com/user-attachments/assets/2e2c03e3-ccfc-4a68-baac-c0c45b9f07f9" />

3. Lengan Bergerak (Modul)
   <img width="1365" height="767" alt="Screenshot 2026-03-24 061542" src="https://github.com/user-attachments/assets/817f7b07-9ee9-4669-9294-7328b84e366a" />
   <img width="1365" height="767" alt="Screenshot 2026-03-24 070838" src="https://github.com/user-attachments/assets/ea520029-59be-4f1a-b0d1-4ee7a13da9f0" />


## TUGAS
1. Cara kerja kode Lengan Bergerak (Modul)
   Pada kode tersebut, lengan dibangun dari 2 balok dengan menggunakan transformasi berurutan yaitu :
   1) `glTranslatef` yaitu untuk memindahkan posisi
   2) `glRotatef` yaitu untuk memutar sendi (joint)
   3) `glScalef` yaitu untuk membentuk balok
   
   Transformasi ini bersifat hierarki yaitu jika bahu bergerak, maka lengan juga ikut bergerak.

   Cara kerjanya adalah :
   1) Titik awal dipindah ke posisi bahu.
   2) Lengan atas diputar dengan variabel `shoulder`.
   3) Balok pertama digambar sebagai lengan atas.
   4) Dari ujungnya, dilakukan rotasi `elbow`.
   5) Balok kedua digambar sebagai lengan bawah.
  
   Pergerakan lengan menggunakan kontrol, yaitu :
   - Tombol keyboard s/S untuk memutar bahu
   - Tombol keyboard e/E untuk memutar siku

2. Penambahan telapak tangan dan jari-jari

   Target dari soal ini adalah untuk menambahkan telapak tangan dan jari-jari yang bisa dikontrol pergerakannya menggunakan keyboard.

   **KODE**
   
   <img width="1365" height="767" alt="Screenshot 2026-03-24 054648" src="https://github.com/user-attachments/assets/61a1e032-0014-44ef-9c2c-c2f0937a96f3" />
   <img width="1365" height="767" alt="Screenshot 2026-03-24 054717" src="https://github.com/user-attachments/assets/39212d48-efb2-46fe-bcf9-47ffd4b02581" />
   <img width="1365" height="767" alt="Screenshot 2026-03-24 054734" src="https://github.com/user-attachments/assets/d8858f11-bf1e-424a-af69-e2e19765137b" />
   <img width="1365" height="767" alt="Screenshot 2026-03-24 054752" src="https://github.com/user-attachments/assets/a7acdbcb-8232-4ed2-88fb-0e5592ef759c" />
   <img width="1365" height="767" alt="Screenshot 2026-03-24 054812" src="https://github.com/user-attachments/assets/96577283-d897-4929-8122-d73a1c8bfe65" />
   <img width="1365" height="767" alt="Screenshot 2026-03-24 054827" src="https://github.com/user-attachments/assets/c30e8879-db13-49d1-a7cc-66e441e0ea38" />

   Pada kode tersebut, diberikan variabel `wrist` sebagai pergelangan tangan, `f1_base=0` sebagai ruas jari bawah kelingking, `f1_tip=0` ruas jari atas kelingking, dst.
   Lalu ditambahkan juga kode untuk membentuk telapak tangan dan jari pada `display()`.
   Setelah itu diberikan kontrol keyboard untuk masing masing objek tersebut.

   **HASIL**
   
   <img width="902" height="633" alt="Screenshot 2026-03-24 054947" src="https://github.com/user-attachments/assets/8f316146-7dfa-41a2-bfcb-eea270f62e5a" />

3. Simulasi menggunakan sumbu x, y, dan z
   
   Diasumsikan bahwa :
   - `glTranslatef(1.0,0,0)` = +100 mm (X)
   - `glTranslatef(0,0.2,0)` = +20 mm (Y)
     
   Contoh :
   
   1) Menggerakkan ruas jari kelingking bawah dengan menekan keyboard '1', yang artinya akan berubah 5 derajat terhadap sumbu Z
     <img width="899" height="631" alt="Screenshot 2026-03-24 091152" src="https://github.com/user-attachments/assets/e6cacc2a-f1ac-442e-9c38-f40ad6cfdaf7" />

   2) Menggerakkan ruas jari kelingking atas dengan menekan keyboard '!', yang artinya akan berubah 5 derajat terhadap sumbu Z
      <img width="899" height="629" alt="Screenshot 2026-03-24 091206" src="https://github.com/user-attachments/assets/ac96d698-d788-496b-bb87-44191772a477" />

   3) Menggerakkan pergelangan dengan menekan keyboard 'w', yang artinya akan berubah 5 derajat terhadap sumbu Z
      <img width="898" height="628" alt="Screenshot 2026-03-24 091229" src="https://github.com/user-attachments/assets/8b2fa910-6f74-4ad5-a3f8-e32f7d561462" />

   4) Menggerakkan bahu dengan menekan keyboard 's', yang artinya akan berubah 5 derajat terhadap sumbu Z
     <img width="899" height="630" alt="Screenshot 2026-03-24 091240" src="https://github.com/user-attachments/assets/87228e6a-bf38-4cd5-b013-983d952e8d36" />

   5) Menggerakkan siku dengan menekan keyboard 'e', yang artinya akan berubah 5 derajat terhadap sumbu Z
      <img width="898" height="629" alt="Screenshot 2026-03-24 091250" src="https://github.com/user-attachments/assets/dd9c0d85-5704-46d7-8032-6da71e7c4ded" />
