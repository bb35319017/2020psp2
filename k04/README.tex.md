# 課題4 レポート

bb35319017 河辺桜

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明

l.5:構造体の宣言

l.22-24:heightのデータファイル名を入力し、fname1に格納、fname1の文字列の最後をヌル文字'\0'に置換

l.33-35:IDのデータファイル名を入力し、fname2に格納、fname2の文字列の最後をヌル文字'\0'に置換

l.44-45:調べたいIDを入力

l.49:ファイルを1行ずつbufに読み込み、読み込み成功する限り繰り返す

l.54-6６:調べたいIDのデータがリストにあれば、性別を判断し、ID,gender、heightを出力し、終了

l.68-71::調べたいIDのデータがリストになければ、nodataと出力し、終了


## 入出力結果

```
C:\Users\sakura\source\pg2\2020psp2\k04>k04
input the file name of sampl height : ../sample/heights.csv
input the file name of sample ID : ../sample/IDs.csv
which ID 's data do you want? : 45313125
---
ID : 45313125
gender : famel
height : 152.4

C:\Users\sakura\source\pg2\2020psp2\k04>k04
input the file name of sampl height : ../sample/heights.csv
input the file name of sample ID : ../sample/IDs.csv
which ID 's data do you want? : 45313124
---
no data
```

## 修正履歴

