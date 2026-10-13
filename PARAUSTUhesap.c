//Bu projede alışveriş sonrası girilen ürün tutarı ve müşterinin verdiği miktar arası farkı bulup müşteriye para üstünün nasıl 
//hatasız ve en az adet para kullanılarak verileceğini hesaplamayı ve sunmayı amaçlar.
//Round fonksiyonu kullanılarak hazırlanan bu uygulama hassas yuvarlama özelliğine de sahiptir.
//Kullanıcısına sade ve anlaşılır bir çıkti sunmaktadır.


#include <stdio.h>
#include <math.h>   // round kullanabilmek için

int main(){
    //KURAL 1
    // Ürünün tutarını ve ödenen parayı float olarak tanımlıyorum
    float urun_tutari, odenen_para;
    
    printf("urun tutarini giriniz(TL):  ");
    scanf("%f", &urun_tutari);

    printf("odenen parayi giriniz(TL):  ");
    scanf("%f", &odenen_para);


    //round() fonksiyonu kullanıyorum
    float tl_fark = odenen_para - urun_tutari;
    int kurus_toplam = (int)round(tl_fark * 100);

    printf("\n____PARA USTU BILGISI____\n");
    printf("Toplam para ustu (kurus cinsinden): %d kurus \n", kurus_toplam);

    int kalan_para = kurus_toplam;             // kalan_para değişkeni müşteriye verilecek olan parayı ifade ediyor
    int toplam_banknot_ve_madeni_para = 0;     // //toplam banknot ve madeni para sayısı başlangıçta 0 ancak ileriki işlemlerde adım adım artar.

    // Her para için ayrı değişkenler tanımlıyoruz
    int adet_200 , adet_100 , adet_50 , adet_20 , adet_10 , adet_5;
    int adet_1tl , adet_50k , adet_25k , adet_10k , adet_5k , adet_1k;

    // 200 TL = 20000 kuruş
    adet_200 = kalan_para / 20000;         //Eldeki toplam kalan kuruşun içinde kaç 20000 kuruş (200 tl) olduğunu bulmak için. 
    kalan_para = kalan_para % 20000;       // mod alma ile 200 lükleri verdikten sonra geriye ne kadar kaldığını hesaplıyoruz ve kalan_para değişkenini güncelliyoruz
    toplam_banknot_ve_madeni_para += adet_200;   //başlangıçta 0 olan para adeti sayısına para adeti ekleme yapıyoruz(küpür sayısını güncelliyoruz).
    printf("%d adet 200 TL\n", adet_200);     //kaç adet 200 tl vermek gerektiğini yazıyoruz.


    //            200 tl de uygulanan mantığı diğer banknot ve madeni paralara da uyguluyoruz

    // 100 TL = 10000 kuruş
    adet_100 = kalan_para / 10000;
    kalan_para = kalan_para % 10000;
    toplam_banknot_ve_madeni_para += adet_100;
    printf("%d adet 100 TL\n", adet_100);

    // 50 TL = 5000 kuruş
    adet_50 = kalan_para / 5000;
    kalan_para = kalan_para % 5000;
    toplam_banknot_ve_madeni_para += adet_50;
    printf("%d adet 50 TL\n", adet_50);

    // 20 TL = 2000 kuruş
    adet_20 = kalan_para / 2000;
    kalan_para = kalan_para % 2000;
    toplam_banknot_ve_madeni_para += adet_20;
    printf("%d adet 20 TL\n", adet_20);

    // 10 TL = 1000 kuruş
    adet_10 = kalan_para / 1000;
    kalan_para = kalan_para % 1000;
    toplam_banknot_ve_madeni_para += adet_10;
    printf("%d adet 10 TL\n", adet_10);

    // 5 TL = 500 kuruş
    adet_5 = kalan_para / 500;
    kalan_para = kalan_para % 500;
    toplam_banknot_ve_madeni_para += adet_5;
    printf("%d adet 5 TL\n", adet_5);

    // 1 TL = 100 kuruş
    adet_1tl = kalan_para / 100;
    kalan_para = kalan_para % 100;
    toplam_banknot_ve_madeni_para += adet_1tl;
    printf("%d adet 1 TL\n", adet_1tl);

    // 50 Kuruş
    adet_50k = kalan_para / 50;
    kalan_para = kalan_para % 50;
    toplam_banknot_ve_madeni_para += adet_50k;
    printf("%d adet 50 Kurus\n", adet_50k);

    // 25 Kuruş
    adet_25k = kalan_para / 25;
    kalan_para = kalan_para % 25;
    toplam_banknot_ve_madeni_para += adet_25k;
    printf("%d adet 25 Kurus\n", adet_25k);

    // 10 Kuruş
    adet_10k = kalan_para / 10;
    kalan_para = kalan_para % 10;
    toplam_banknot_ve_madeni_para += adet_10k;
    printf("%d adet 10 Kurus\n", adet_10k);

    // 5 Kuruş
    adet_5k = kalan_para / 5;
    kalan_para = kalan_para % 5;
    toplam_banknot_ve_madeni_para += adet_5k;
    printf("%d adet 5 Kurus\n", adet_5k);

    // 1 Kuruş
    adet_1k = kalan_para / 1;
    kalan_para = kalan_para % 1;
    toplam_banknot_ve_madeni_para += adet_1k;
    printf("%d adet 1 Kurus\n", adet_1k);
    
    //2.KURAL
    // Toplam sayıyı güncellenen değişken adıyla yazdırıyorum
    printf("\nMusteriye verilen TOPLAM banknot ve madeni para sayisi: %d\n", toplam_banknot_ve_madeni_para);

    return 0;
}
//PROGRAMI GELİŞTİRME SÜRECİNDE YARARLANILAN KAYNAKLAR:
//https://www.scaler.com/topics/c-round/       round fonksiyonunu ve örneklerini incelemek için kullanılmıştır.
//visual studio code          kod yazarken kullanılmıştır.
//gemini            üzerinden round fonksiyonu kullanımında ve bazı mantık hatalarını çözmede zaman zaman yardım alınmıştır.