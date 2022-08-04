# Philosophers

## Genel Bakış

Bilgisayar biliminde, yemek yiyen filozof problemi, senkronizasyon problemlerini ve bunları çözme tekniklerini göstermek için eşzamanlı algoritma tasarımında sıklıkla kullanılan örnek bir problemdir.
İlk olarak 1965 yılında Edsger Dijkstra tarafından sunulan bir öğrenci sınav alıştırması olarak formüle edilmiştir. Kısa bir süre sonra, Tony Hoare soruna mevcut şeklini verdi.

<img width="320" alt="philos" src="https://user-images.githubusercontent.com/81527587/182756099-63c31ce9-76e6-40eb-9314-dd3911a4e90f.png">

N sayıda filozof aynı sofrada birlikte yemek yer. Bu örnekteki felsefeci sorunları, servis edilen yemeğin iki çatalla yenmesi gereken bir tür spagetti olmasıdır yani bir filozofun yemek yemesi durumunda o filozofun yanındaki filozoflar yemek yiyememekte.

Her tabak arasında bir çatal var. Her filozof sadece dönüşümlü olarak düşünebilir ve yiyebilir. Dahası, bir filozof spagettisini ancak hem sol hem de sağ çatalları olduğunda yiyebilir. Böylece iki çatal, ancak en yakın iki komşusu yemek yemezken kullanılabilir olacaktır. Bireysel bir filozof yemeyi bitirdikten sonra, her iki çatalı da bırakacaktır. Sorun, hiçbir filozofun açlıktan ölmeyeceği eşzamanlı bir  algoritmanın nasıl tasarlanacağıdır; yani , hiçbir filozofun diğerlerinin ne zaman yemek yemek isteyebileceğini veya düşünmek isteyebileceğini bilemeyeceğini varsayarak, her biri sonsuza kadar yeme ve düşünme arasında gidip gelmeye devam edebilir.

## Kurallar

| Tanımlar                                                                                                         |
| --------------------------------------------------------------------------------------------------------------------| 
| • Bir veya daha fazla filozof yuvarlak bir masada oturuyor. Masanın ortasında büyük bir kase spagetti var.          |
| • Filozoflar alternatif olarak yer, düşünür veya uyur. aynı anda ya yer ya düşünür ya da uyur.                      |
| • Masada çatallar da vardır. Filozoflar kadar çatal vardır.                                                         |
| • Filozof yemek yemek için sağ ve sol çatallarını her iki elinde birer tane alır.                                   |
| • Filozof yemeğini bitirince çatallarını masaya koyar ve uyumaya başlar. Uyandıklarında tekrar düşünmeye başlarlar. |
| • Bir filozof açlıktan öldüğünde simülasyon durur.                                                                  |
| • Her filozofun yemek yemesi gerekir ve asla aç kalmamalıdır.                                                       |
| • Filozoflar başka bir filozofun ölmek üzere olup olmadığını bilmiyorlar.                                           |

## Özel Kurallar

| Tanımlar                                                                                             |
| -----------------------------------------------------------------------------------------------------| 
| • Her filozof bir thread olmalıdır.                                                                  |
| • Birden fazla filozof varsa, her filozofun sol tarafında bir çatal, sağ tarafında bir çatal vardır. |
| • Sadece bir filozof varsa, masada sadece bir çatal olmalıdır.                                       |
| • Filozofların çatalları çoğaltmasını önlemek için, çatalların durumunu muteksler ile korumalısınız. |

![basic_img](https://user-images.githubusercontent.com/81527587/182758634-fd8988c5-3965-4f37-a80c-6b88d234ad9d.png)

## Argümanlar

(./philo philo_count time_to_die eating_time sleeping_time eat_destination)
(./philo 10 800 310 200)
(./philo 10 800 310 200 5)

| Tanımlar                                                              |
| ----------------------------------------------------------------------| 
| • philo_count: Filozof sayısını belirtir.                             |
| • time_to_die: Bir filozofun aç kaldığında ölme süresi.               |
| • eating_time: Filozofun yemek yerken harcadığı süre.                 |
| • sleeping_time: Filozofun yemekden sonraki uyuma süresi.             |
| • eat_destination: Her bir filozofun yemek yeme hedefi. (isteğe bağlı)|




