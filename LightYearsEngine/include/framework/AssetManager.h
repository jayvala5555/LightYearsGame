#pragma once
#include "SFML/Graphics.hpp"
#include "framework/Core.h"

namespace ly
{

// singleton class implementation
class AssetManager
{
public:
    // get asset manager instance.
    static AssetManager& get();
    // load texture from path.
    lySP<sf::Texture> loadTexture(const std::string& path);
    // clean cycle for remvoing unused texutre from dictionary
    void cleanCycle();
    // set asset root directory.
    void setAssetRootDir(const std::string& dir);
protected:
    // constructor in protected in case of singleton class.
    AssetManager();
private:
    // globally single asset manager.
    static lyUP<AssetManager> assetManager;
    // loaded texture dictionary with path.
    lyDict<std::string, lySP<sf::Texture>> mLoadedTextureMap;
    // asset root directory path.
    std::string mRootDir;
};

    
} // namespace ly
