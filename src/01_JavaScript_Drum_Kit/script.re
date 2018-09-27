open Webapi.Dom;

let playSound = e => {
  let keyCode = KeyboardEvent.code(e);
  let audio =
    document |> Document.querySelector({j|audio[data-key="$keyCode"]|j});
  let key =
    document |> Document.querySelector({j|.key[data-key="$keyCode"]|j});
  switch (audio, key) {
  | (Some(audio), Some(key)) =>
    audio.currentTime = 0;
    audio.play();
    key.classList.add("playing");
  | (_, _) => ()
  };
};

let removePlayingClass = e =>
  e.propertyName === "transform" && e.target.classList.remove("playing");

let keys = document |> Document.querySelectorAll(".key");

keys.forEach(key =>
  key.addEventListener("transitionend", removePlayingClass)
);

Window.addKeyDownEventListener(playSound, window);
