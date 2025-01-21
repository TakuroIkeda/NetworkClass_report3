# NetWorkClass Report 3

このプロジェクトは、ノード間の距離をシミュレーションし、成功確率を計算するプログラムです。

## ファイル構成

- `src/simulate.c`: シミュレーションの主要なロジックを含むソースコード。
- `include/simulate.h`: シミュレーション関数のヘッダーファイル。
- `include/define.h`: 定数定義のヘッダーファイル。
- `app/main.c`: プログラムのエントリーポイント。

## 使用方法

1. プロジェクトをクローンします。
    ```sh
    git clone https://github.com/yourusername/NetWorkClass_report3.git
    cd NetWorkClass_report3
    ```

2. プロジェクトをビルドします。
    ```sh
    make
    ```

3. プログラムを実行します。
    ```sh
    ./app/main
    ```

## 結果

結果は`./result/probability.txt`に保存されます。各行にはノード数と成功確率がタブ区切りで記録されます。

## ライセンス

このプロジェクトはMITライセンスの下で公開されています。詳細は`LICENSE`ファイルを参照してください。
