#include <stdio.h>
#include <stdint.h>

// 1. Standart Enum
enum Color {
    RED,
    GREEN,
    BLUE
};
// Açıklama: Standart enum, sıralı sabit değerler tanımlar.
// Avantajları:
// - Kullanımı basittir ve kodu daha okunabilir hale getirir.
// - Derleyici tarafından otomatik olarak numaralandırılır (0'dan başlar).
// Dezavantajları:
// - Varsayılan olarak int boyutunda yer kaplar (genellikle 4 byte).
// Kullanım alanları:
// - Sabit değer kümeleri için (örn: renk seçenekleri, durum kodları).

// 2. Explicit Değerli Enum
enum Weekday {
    MONDAY = 1,
    TUESDAY = 2,
    WEDNESDAY = 3,
    THURSDAY = 4,
    FRIDAY = 5,
    SATURDAY = 6,
    SUNDAY = 7
};
// Açıklama: Her enum sabitine açıkça değer atanmış enum.
// Avantajları:
// - Özel numaralandırma gerektiğinde kullanışlıdır.
// - Değerler arasında boşluklar bırakılabilir veya özel anlamlı sayılar kullanılabilir.
// Dezavantajları:
// - Elle değer atama hataya açık olabilir (örn: tekrarlanan değerler).
// Kullanım alanları:
// - Protokol tanımlamaları, özel kodlama şemaları.

// 3. Typedef ve Packed Enum
typedef enum __attribute__((packed)) {
    IDLE,
    RUNNING,
    PAUSED,
    STOPPED
} ProcessState_t;
// Açıklama: Typedef ile yeni bir tür adı tanımlanmış ve packed attribute ile optimize edilmiş enum.
// Avantajları:
// - Minimum bellek kullanımı (değer aralığına göre 1, 2 veya 4 byte).
// - Typedef sayesinde daha temiz syntax.
// Dezavantajları:
// - Platform bağımlı olabilir, bazı derleyicilerde desteklenmeyebilir.
// Kullanım alanları:
// - Gömülü sistemlerde, bellek hassasiyeti yüksek uygulamalarda.

// 1. Standart Struct
struct Point {
    int x;
    int y;
};
// Açıklama: En temel struct türüdür.
// Avantajları:
// - Kullanımı basittir ve çoğu durumda yeterlidir.
// - Derleyici, veri hizalaması yaparak genellikle daha hızlı bellek erişimi sağlar.
// Dezavantajları:
// - Bellek hizalaması nedeniyle fazladan alan kullanabilir (padding).
// Kullanım alanları:
// - Genel amaçlı programlamada sıkça kullanılır.
// - Performansın bellek kullanımından daha önemli olduğu durumlarda tercih edilir.

// 2. Typedef Struct
typedef struct {
    float latitude;
    float longitude;
} Coordinate;
// Açıklama: Struct'a yeni bir tür adı verir.
// Avantajları:
// - Kullanımı daha kolaydır, 'struct' anahtar kelimesi kullanmaya gerek kalmaz.
// - Kod okunabilirliğini artırır, özellikle karmaşık projelerde.
// Dezavantajları:
// - Orijinal struct adı kaybolabilir, bu bazen debug'ı zorlaştırabilir.
// Kullanım alanları:
// - Büyük projelerde kod organizasyonunu iyileştirmek için.
// - API tasarımında, kullanıcı dostu arayüzler oluşturmak için.

// 3. Packed Struct
struct __attribute__((packed)) PackedData {
    uint8_t  id;
    uint32_t timestamp;
    uint16_t value;
    uint8_t  status;
};
// Açıklama: Bellek hizalaması olmadan minimum alanda saklanır.
// Avantajları:
// - Minimum bellek kullanımı sağlar, her byte etkin kullanılır.
// - Sabit boyutlu veri yapıları oluşturmak için idealdir.
// Dezavantajları:
// - Bazı işlemcilerde performans kaybına neden olabilir.
// - Hizalanmamış bellek erişimi, bazı platformlarda sorunlara yol açabilir.
// Kullanım alanları:
// - Gömülü sistemlerde, sınırlı bellek olan ortamlarda.
// - Ağ protokollerinde, veri paketlerinin kesin boyutlarını tanımlamak için.
// - Dosya formatlarında, sabit boyutlu kayıtlar oluşturmak için.

void printEnumSizes() {
    printf("Enum Boyutları:\n");
    printf("sizeof(enum Color): %zu bytes\n", sizeof(enum Color));
    printf("sizeof(enum Weekday): %zu bytes\n", sizeof(enum Weekday));
    printf("sizeof(ProcessState_t): %zu bytes\n", sizeof(ProcessState_t));
}

void printStructSizes() {
    printf("Struct Boyutları:\n");
    printf("sizeof(struct Point): %zu bytes\n", sizeof(struct Point));
    printf("sizeof(Coordinate): %zu bytes\n", sizeof(Coordinate));
    printf("sizeof(struct PackedData): %zu bytes\n", sizeof(struct PackedData));
}

int main() {
    // Enum örnekleri
    enum Color myColor = BLUE;
    enum Weekday today = WEDNESDAY;
    ProcessState_t currentState = RUNNING;

    // Struct örnekleri
    struct Point point = {10, 20};
    Coordinate coord = {40.7128, -74.0060};
    struct PackedData data = {5, 1628097523, 1000, 1};

    printEnumSizes();
    printStructSizes();

    printf("\nEnum Değerleri:\n");
    printf("Color: %d\n", myColor);
    printf("Weekday: %d\n", today);
    printf("ProcessState: %d\n", currentState);

    printf("\nStruct Değerleri:\n");
    printf("Point: (%d, %d)\n", point.x, point.y);
    printf("Coordinate: (%.4f, %.4f)\n", coord.latitude, coord.longitude);
    printf("PackedData: id=%u, timestamp=%u, value=%u, status=%u\n",
           data.id, data.timestamp, data.value, data.status);

    return 0;
}