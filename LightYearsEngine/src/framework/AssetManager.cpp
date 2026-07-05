#include "framework/AssetManager.h"

namespace ly
{

lyUP<AssetManager> AssetManager::assetManager{nullptr};

AssetManager::AssetManager()
{

}

//////////////////////////////////////////////////////////////////////

AssetManager& AssetManager::get()
{
    if (!assetManager)
    {
        // assetManager = std::move(lyUP<AssetManager>{new AssetManager});
        assetManager = lyUP<AssetManager>{new AssetManager};
    }
    return *assetManager;
}

//////////////////////////////////////////////////////////////////////

lySP<sf::Texture> AssetManager::loadTexture(const std::string &path)
{
    auto found = mLoadedTextureMap.find(path);
    if (found != mLoadedTextureMap.end())
    {
        return found->second;
    }

    lySP<sf::Texture> newTexture{ new sf::Texture};
    if (newTexture->loadFromFile(path))
    {
        mLoadedTextureMap.insert({path, newTexture});
        return newTexture;
    }

    return lySP<sf::Texture> {nullptr};
}

//////////////////////////////////////////////////////////////////////

void AssetManager::cleanCycle()
{
    for (auto itr = mLoadedTextureMap.begin(); itr != mLoadedTextureMap.end(); )
    {
        if (itr->second.unique())
        {
            LOG("Cleaning texture: %s", itr->first.c_str());
            itr = mLoadedTextureMap.erase(itr);
        }
        else
        {
            ++itr;
        }
    }
}

} // namespace ly
