# 📊 Sharpe Oranı Hesaplama Programı (C Dili)

Bu program, bir yatırım portföyünün **Sharpe Oranı**’nı hesaplamak için geliştirilmiştir.  
Sharpe Oranı, bir yatırımın **riskine göre ne kadar ek getiri sağladığını** ölçer.  
Yani, “aldığın riske değmiş mi?” sorusunun cevabını verir.

---

## 🧠 Sharpe Oranı Formülü

\[
\text{Sharpe Oranı} = \frac{Yatırım Getirisi - Risksiz Faiz Oranı}{Standart Sapma}
\]

- **Yatırım Getirisi (getiri):** Portföyün yıllık kazancı (örneğin %15 → 0.15)  
- **Risksiz Faiz Oranı (risksizOran):** Devlet tahvili gibi risksiz yatırımların getirisi  
- **Standart Sapma (risk):** Portföyün riskini ölçen değişken

---

## ⚙️ Programın Amacı

Bu C programı kullanıcıdan;
1. Yıllık yatırım getirisini,  
2. Risksiz faiz oranını,  
3. Portföyün standart sapmasını (riskini)  
alır ve Sharpe oranını hesaplar.

Daha sonra bu oranı **yorumlayarak** yatırımın performansı hakkında bilgi verir.

---

## 🧩 Kodun Ana Bölümleri

### 1. `main()` Fonksiyonu
Programın başlangıç noktasıdır.  
Kullanıcıdan veri alır, oranı hesaplar ve sonucu ekrana yazar.

### 2. `hesaplaSharpeOrani()` Fonksiyonu
Girilen değerlerle Sharpe oranını hesaplar.  
```c
return (getiri - risksizOran) / standartSapma;
```

### 3. `yorumlaSharpeOrani()` Fonksiyonu
Hesaplanan Sharpe oranını anlamlandırır:
- `3.0 ve üzeri` → Mükemmel  
- `2.0 - 2.99` → Çok iyi  
- `1.0 - 1.99` → İyi  
- `0.0 - 0.99` → Kabul edilebilir  
- `< 0.0` → Kötü (risk almaya değmez)

---

## 💻 Kullanım

1. Kodu bir dosyaya kaydedin:  
   **`sharpe.c`**

2. Terminal veya komut satırında derleyin:
   ```bash
   gcc sharpe.c -o sharpe
   ```

3. Programı çalıştırın:
   ```bash
   ./sharpe
   ```

4. Ekrandaki yönlendirmeleri takip edin:

   ```
   --- Sharpe Orani Hesaplama Programi ---
   Yillik Yatirim Getirisini giriniz (%): 15
   Risksiz Faiz Oranini giriniz (%): 5
   Portföyün Standart Sapmasini giriniz (%): 12
   ```

---

## 📈 Örnek Çalışma

**Girdi:**
```
Yatırım Getirisi: 15
Risksiz Oran: 5
Standart Sapma: 12
```

**Çıktı:**
```
--- Hesaplama Sonucu ---
Yatirim Getirisi: 15.00%
Risksiz Oran:     5.00%
Standart Sapma:   12.00%
--------------------------
Hesaplanan Sharpe Orani: 0.8333
--------------------------
Kabul Edilebilir: Portföy, risksiz orandan daha iyi bir getiri saglamistir, ancak risk-getiri dengesi gelistirilebilir.
```

---

## 🧮 Teknik Detaylar

- `%lf`: `scanf` ile double veri türünde sayı almak için kullanılır.  
- `%.2f`: Sayıyı **virgülden sonra 2 basamak** göstermek için kullanılır.  
- `double`: Ondalık (kesirli) sayıları depolamak için kullanılır.  
- `if - else if`: Karar yapılarıyla oran aralıklarını kontrol eder.  

---

## 👨‍💻 Yazar
**Hazırlayan:** İsmail Gürbüz  
**Dil:** C  
**Konu:** Finansal Hesaplama – Sharpe Oranı  
**Amaç:** Portföy performansını ölçmek ve yorumlamak  

---

## 🏁 Sonuç

Bu program sayesinde kullanıcılar:
- Yatırımlarının risk düzeyine göre getirilerini analiz edebilir,  
- Sharpe oranını öğrenip **portföy kalitesini** değerlendirebilir.

---

> 💡 **Not:** Standart sapma sıfır girilirse program hata verir, çünkü sıfıra bölme matematiksel olarak tanımsızdır.

---
