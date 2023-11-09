#pragma once

enum SCENE {
	TITLE,
	STAGE,
	CLEAR,
};

class IScene
{
protected:

	static int sceneNo;

public:
	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Init() = 0;
	/// <summary>
	/// 更新
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw() = 0;

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~IScene();

	/// <summary>
	/// シーン番号取得
	/// </summary>
	/// <returns></returns>
	int GetSceneNo();

};

