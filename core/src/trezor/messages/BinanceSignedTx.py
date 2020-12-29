# Automatically generated by pb2py
# fmt: off
import protobuf as p

if __debug__:
    try:
        from typing import Dict, List  # noqa: F401
        from typing_extensions import Literal  # noqa: F401
    except ImportError:
        pass


class BinanceSignedTx(p.MessageType):
    MESSAGE_WIRE_TYPE = 709

    def __init__(
        self,
        *,
        signature: bytes = None,
        public_key: bytes = None,
    ) -> None:
        self.signature = signature
        self.public_key = public_key

    @classmethod
    def get_fields(cls) -> Dict:
        return {
            1: ('signature', p.BytesType, None),
            2: ('public_key', p.BytesType, None),
        }
