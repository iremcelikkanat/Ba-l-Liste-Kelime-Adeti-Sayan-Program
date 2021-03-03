 # BAGLI LİSTE UYGULAMALARI PROJESİ

## 1.	Problem Tanımı

Bu proje genel olarak bağlı liste yapısını
kullanarak verilen kelimeler.txt dosyasından veriyi çekerek bu verileri bağlı listeler yardımıyla sıralı yapıda tutmayı sağlar. Sonucunda veriler bağlı
listeye büyükten küçüğe sıralı bir şekilde yüklenmiş
bulunmaktadır.

Şekil 1 Txt'den girilen örnek ekran çıktısı

![Ekran görüntüsü 2021-03-04 002505](https://user-images.githubusercontent.com/56557278/109874389-1c74b200-7c80-11eb-9675-cefc0067788c.jpg)

- A.	TEMEL BİLGİLER

Program C programlama dilinde gerçekleştirilmiş olup geliştirme ortamı olarak CodeBlocks kullanılmıştır.

- B. Algoritma

Bağlı liste uygulamaları projesi kelime verilerini sistemde sıralı yapıda tutar. Text içerisindeki
kelimeleri sayarak bağlı listeye adet olarak büyükten küçüğe doğru eleman ekler. Uygulamada her seferinde yeni bir kelimeye göre metin içerisinde arama yapar ve metin içerisinde geçen kelimeleri sayar. Uygulamada işlem sırası metin içerisinde kelimeyi bulup, adet sayısını hesaplayıp, büyükten küçüğe doğru bağlı listeye eklenmesi şeklindedir. Bağlı liste kelime ve adet bilgisi içerir. Bağlı liste içerisinde bir kelime sadece bir kez bulunur. Bağlı liste büyükten küçüğe doğru sıralalıdır. Bağlı listede başa, sona ve araya ekleme metotlarının tümü kullanılılmıştır.
 


## 2.	PROJENİN GENEL YAPISI
Projede temel olarak txt dosyasından okutulan kelimeler adetleri sayılarak büyükten küçüğe bağlı listeye ekleme yapılmaktadır. Bu işlemler sırasıyla; dosyadan okuma, sayma,
karşılaştırma, sıralama ve sona, başa, araya ekleme yapılarak gerçekleştirilmektedir. Sonucunda
kelimeler ve adet sayıları sıralı olarak bağlı listeden konsola ve txt dosyasına yazdırılmaktadır.

 
Şekil 2 İlk Hali (Console Çıktısı)
 
![1](https://user-images.githubusercontent.com/56557278/109873176-76747800-7c7e-11eb-9f90-44421ccb8d9b.png)


## 3.	AKIŞ DİYAGRAMI

![3](https://user-images.githubusercontent.com/56557278/109873306-9efc7200-7c7e-11eb-9b1b-7cefb2411229.png)
