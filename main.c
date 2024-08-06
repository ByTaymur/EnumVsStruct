#include <stdio.h>
#include <stdint.h>

// 1. Standart Enum
enum Color {
    RED,
    GREEN,
    BLUE
};
// Teknik Detaylar:
// - Bellek Kullanımı: Genellikle 4 byte (int boyutu)
// - Bellek Düzeni: Sıralı tam sayılar (0, 1, 2, ...)
// - Erişim: Doğrudan değer erişimi, switch-case yapılarında verimli
// - Kullanım: Sabit değer kümeleri, durum makineleri

// 2. Explicit Değerli Enum
enum Weekday {
    MONDAY = 1,
    TUESDAY = 2,
    WEDNESDAY = 4,
    THURSDAY = 8,
    FRIDAY = 16,
    SATURDAY = 32,
    SUNDAY = 64
};
// Teknik Detaylar:
// - Bellek Kullanımı: Genellikle 4 byte, ancak en büyük değere bağlı
// - Bellek Düzeni: Özel atanmış değerler, bit maskesi olarak kullanılabilir
// - Erişim: Doğrudan değer erişimi, bit işlemleri için uygun
// - Kullanım: Bayraklar (flags), bit maskeleri, özel kodlama şemaları

// 3. Typedef ve Packed Enum
typedef enum __attribute__((packed)) {
    IDLE,
    RUNNING,
    PAUSED,
    STOPPED
} ProcessState_t;
// Teknik Detaylar:
// - Bellek Kullanımı: Minimum gerekli boyut (bu örnekte 1 byte)
// - Bellek Düzeni: Sıkıştırılmış, hizalama yok
// - Erişim: Potansiyel olarak daha yavaş (platforme bağlı)
// - Kullanım: Bellek hassas uygulamalar, gömülü sistemler

// 1. Standart Struct
struct Point {
    int x;
    int y;
};
// Teknik Detaylar:
// - Bellek Kullanımı: 8 byte (2 * sizeof(int))
// - Bellek Düzeni: Hizalanmış, potansiyel padding
// - Erişim: Hızlı, doğrudan bellek erişimi
// - Kullanım: Genel amaçlı veri gruplandırma

// 2. Typedef Struct
typedef struct {
    float latitude;
    float longitude;
} Coordinate;
// Teknik Detaylar:
// - Bellek Kullanımı: 8 byte (2 * sizeof(float))
// - Bellek Düzeni: Standart struct ile aynı
// - Erişim: Standart struct ile aynı
// - Kullanım: Temiz syntax, nesne yönelimli benzeri tasarım

// 3. Packed Struct
struct __attribute__((packed)) PackedData {
    uint8_t  id;
    uint32_t timestamp;
    uint16_t value;
    uint8_t  status;
};
// Teknik Detaylar:
// - Bellek Kullanımı: 8 byte (1 + 4 + 2 + 1), sıkıştırılmış
// - Bellek Düzeni: Hizalama yok, her byte kullanılır
// - Erişim: Potansiyel olarak daha yavaş, hizalanmamış erişim
// - Kullanım: Seri iletişim protokolleri, dosya formatları, bellek hassas uygulamalar

void printSizes() {
    printf("Enum Boyutları:\n");
    printf("sizeof(enum Color): %zu bytes\n", sizeof(enum Color));
    printf("sizeof(enum Weekday): %zu bytes\n", sizeof(enum Weekday));
    printf("sizeof(ProcessState_t): %zu bytes\n", sizeof(ProcessState_t));

    printf("\nStruct Boyutları:\n");
    printf("sizeof(struct Point): %zu bytes\n", sizeof(struct Point));
    printf("sizeof(Coordinate): %zu bytes\n", sizeof(Coordinate));
    printf("sizeof(struct PackedData): %zu bytes\n", sizeof(struct PackedData));
}

int main() {
    printSizes();

    // Bellek düzeni ve erişim örneği
    struct PackedData data = {5, 1628097523, 1000, 1};
    uint8_t* ptr = (uint8_t*)&data;

    printf("\nPackedData Bellek Düzeni:\n");
    for (size_t i = 0; i < sizeof(struct PackedData); i++) {
        printf("%02X ", ptr[i]);
    }
    printf("\n");

    return 0;
}