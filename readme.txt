accコマンド

標準入力に入力された数値列の統計量(平均・分散etc)を計算する

(@sakanazensen)

○機能
・統計量
現時点では次の統計量をサポート
総和，最小値，最大値，平均値，分散，中央値
数値が大きすぎる・小さすぎる場合などは誤差が大きくなる可能性があります

・出力形式
Cのprintf形式でのフォーマットをサポート
例えば"%.0f"と指定すれば計算結果を整数に切り捨てて出力

○ライセンス
MITライセンス

○ビルド・インストール方法
(Ubuntu 11.10)
gcc，automake，autoconf，boostライブラリが必要です．

% autoscan
% autoheader
% aclocal
% automake --add-missing --copy
% autoconf
% ./configure
% make; sudo make install

○使用方法
% acc --help
を参照してください．

○Tips
・整数で出力
% acc --sum -f "%.f"


