#include <stdio.h>
// Sharpe Oranı Formülü: (Yatırım Getirisi - Risksiz Faiz Oranı) / Standart Sapma
// Fonksiyon prototipi: Sharpe oranını hesaplar
double hesaplaSharpeOrani(double getiri, double risksizOran, double standartSapma);

// Fonksiyon prototipi: Sharpe oranını yorumlar
void yorumlaSharpeOrani(double sharpeOrani);

int main() {
    // Giriş değişkenleri
    double yatirimGetirisi;
    double risksizFaizOrani;
    double standartSapma;
    double sharpeOrani;

    printf("--- Sharpe Orani Hesaplama Programi ---\n");

    // 1. Yatırım Getirisini Al
    printf("Yillik Yatirim Getirisini (örnegin 0.15 icin 15) giriniz (%%): ");
    scanf("%lf", &yatirimGetirisi);

    // 2. Risksiz Faiz Oranını Al
    printf("Risksiz Faiz Oranini (örnegin 0.05 icin 5) giriniz (%%): ");
    scanf("%lf", &risksizFaizOrani);

    // 3. Portföyün Standart Sapmasını (Riski) Al
    printf("Portföyün Standart Sapmasini (örnegin 0.12 icin 12) giriniz (%%): ");
    scanf("%lf", &standartSapma);

    // Girilen yüzdelik değerleri ondalık formata dönüştür
    yatirimGetirisi /= 100.0;
    risksizFaizOrani /= 100.0;
    standartSapma /= 100.0;

    // Standart sapmanın sıfır olup olmadığını kontrol et
    if (standartSapma <= 0.0) {
        printf("\nHATA: Standart sapma sifir veya negatif olamaz. Hesaplama yapilamadi.\n");
        return 1; // Hata kodu ile çık
    }

    // Sharpe oranını hesapla
    sharpeOrani = hesaplaSharpeOrani(yatirimGetirisi, risksizFaizOrani, standartSapma);

    // Sonuçları göster
    printf("\n--- Hesaplama Sonucu ---\n");
    printf("Yatirim Getirisi: %.2f%%\n", yatirimGetirisi * 100.0);
    printf("Risksiz Oran:     %.2f%%\n", risksizFaizOrani * 100.0);
    printf("Standart Sapma:   %.2f%%\n", standartSapma * 100.0);
    printf("--------------------------\n");
    printf("Hesaplanan Sharpe Orani: %.4f\n", sharpeOrani);
    printf("--------------------------\n");

    // Oranı yorumla
    yorumlaSharpeOrani(sharpeOrani);

    return 0; // Başarılı çıkış
}

double hesaplaSharpeOrani(double getiri, double risksizOran, double standartSapma) {
    // Risksiz faiz oranının sıfır veya negatif olması durumunda kontrolü main fonksiyonunda yaptık.
    // Hesaplama:
    return (getiri - risksizOran) / standartSapma;
}

/**
 Sharpe Oranının Değerlendirilmesi  */

void yorumlaSharpeOrani(double sharpeOrani) {
    printf("\n--- Sharpe Orani Yorumu ---\n");

    if (sharpeOrani >= 3.0) {
        printf("Mükemmel: Portföy, riskine karsilik cok yüksek bir fazlalik getiri (risk primi) saglamaktadir.\n");
    } else if (sharpeOrani >= 2.0) {
        printf("Cok Iyi: Portföy, riskine karsilik önemli ölçüde iyi bir fazlalik getiri saglamaktadir.\n");
    } else if (sharpeOrani >= 1.0) {
        printf("Iyi: Portföy, kabul edilebilir düzeyde iyi bir risk-ayarlı getiri saglamaktadir.\n");
    } else if (sharpeOrani > 0.0) {
        printf("Kabul Edilebilir: Portföy, risksiz orandan daha iyi bir getiri saglamistir, ancak risk-getiri dengesi gelistirilebilir.\n");
    } else {
        printf("Kötü: Portföy, risksiz orana karsilik ya negatif ya da sifira yakin bir fazlalik getiri saglamistir. Bu, portföyün riskini tasimaya degmedigi anlamina gelebilir.\n");
    }
}